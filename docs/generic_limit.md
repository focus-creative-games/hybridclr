# 泛型

clr中有两类泛型特性：泛型类型和泛型函数。泛型是c#中使用极其广泛的特性。即使一个没有明显包含泛型的用法，可能隐含了泛型相关的定义或者操作。例如 int[]隐含就实现 IEnemrable&lt;int&gt; 之类的接口。又如 为async生成状态机代码时，也会隐含生成一些对System.Runtime.CompilerServices.AsyncTaskMethodBuilder`1&lt;!T&gt;::AwaitUnsafeOnCompleted&lt;!!T1,!!T2&gt; 之类的泛型代码。

## AOT泛型引发的问题

huatuo实现了相当完整的clr特性，纯解释器部分的泛型无任何使用限制，但对于AOT泛型类则存在一些问题。

例如，你在热更新脚本里定义了个值类型

```c#
struct MyVector2
{
    public int x;
    public int y;
}
```

想在脚本中创建List&lt;MyVector2&gt; 这样的类型，通常来说是不可能的，因为List&lt;T&gt;的函数实现跟T直接相关，不同的T相应的代码不同，而List是AOT泛型类，它已经提前编译为native代码，已经无法根据T运行时得到正确的处理代码。故即使huatuo是个功能完整的的运行时，对这种AOT泛型也无法处理。

本质上，因为AOT翻译导致原始IL指令元数据的缺失，进行无法创建出AOT泛型类的新类型的实例。如果原先在AOT中已经生成代码的类型，例如假设你在AOT中用过List&lt;int&gt;，则在huatuo可以完整使用。

泛型类，尤其是泛型容器List,Dictionary之类在代码中使用如此广泛，如果因为AOT限制，导致List&lt;YourHotUpdateType&gt;都不能运行，那游戏热更新的代码受限就太大了。幸运的是，il2cpp无心插柳的一个设计极大缓解了这个问题。

## Generic Sharing

先说一下现在的缓解后的限制。 以List&lt;T&gt; 举例。你可以创建出AOT中使用过的任何List的实例化类型。 你可以对脚本中的任意自定义枚举MyHotUpdateEnum使用 List&lt;MyHotUpdateEnum&gt;。 你可以对于任意的class类型C，使用List&lt;C&gt;。

il2cpp为此引入一个概念叫**泛型代码共享** [Generic Sharing](https://blog.unity.com/technology/il2cpp-internals-generic-sharing-implementation),此技术更早则源于mono。CLR中也有同样的概念，CLR认为所有引用类型实参都一样，所以可以代码共享，例如，为List&lt;String&gt;方法编译的代码可以直接用于List&lt;Stream&gt;方法，这是因为所有引用类型实参/变量只是指向托管堆的一个8字节指针（这里假设64位系统），但是对于值类型，则必须每种类型都进行代码生成，因为值类型大小不定

il2cpp为了避免泛型代码膨胀，节约内存，在保证代码逻辑正确性的情况下对于一些能够共享代码(什么情况下能够共享?：因为值类型内存大小不定，所以无法共享)，只生成一份代码。

其中一个最常见的情况，对引用类型和int以及enum类型，生成共享代码。

同样以List&lt;T&gt;为例。 List&lt;object&gt;和List&lt;string&gt;的 Count 函数，生成一份代码是完全合理正确的。

那il2cpp会泛型类型，生成哪些共享代码呢。这里引入一个概念叫**共享归结类型(sharing reduce type)**(不要google了，这词是我发明的)。

## Sharing Reduce Type

计算规则如下

### 非枚举的值类型

reduce type为自身。如int的reduce type为int

### 枚举类型

reduce type为 underlying type与它相同的枚举。例如

```c#
enum MyEnum 
{
    A = 1,
}

enum MyEnum2 :uint8
{
    A = 10,
}
```

MyEnum的reduce type为 Int32Enum,MyEnum2的reduce type为 Uint8Enum。

### class引用类型

reduce type为 object

### 泛型类型

GenericType&lt;T1,T2,...&gt; 如果是class类型则reduce type为object，否则reduce type为 GenericType&lt;ReduceType&lt;T1&gt;, ReduceType&lt;T2&gt;...&gt;。

例如

- Dictionary&lt;int, string&gt;的reduce type为object。
- YourValueType&lt;int, string&gt;的reduce type为YourValueType&lt;int,object&gt;

## Reduce Type的函数共享

对泛型类型的所有泛型实例化参数进行Sharing Reduce Type计算后，得到最终的泛型共享类型(final sharing generic type) GenericType&lt;ReduceType&lt;T1&gt;, ReduceType&lt;T2&gt;...&gt;。

粗略来说（实际规则远比这个复杂，尤其是泛型函数共享），il2cpp会为泛型生成它的共享类型的共享函数。所有相同reduce type的类的**可共享**(不是所有函数都可共享)这些函数。

举例 List&lt;object&gt;, List&lt;string&gt;, List&lt;GameObject&gt;的Count 函数，都对应同一份代码，这几个类的的运行时元数据中的Count函数的函数指针都指向相同的c++函数。

至此真相大白，这就是为什么huatuo允许你在热更新代码中随意使用List&lt;YourClassType&gt;的原因。

## 泛型函数

对于普通的非虚成员或者静态泛型函数，如示例中 void Fire&lt;T&gt;(T obj)，它有跟泛型类成员函数相似的代码共享规则。这意味着对于 go.AddComponent&lt;YourHotUpdateMonoBehaviour&gt;() 这样的泛型函数，尽管你从未在AOT中使用过它，你仍然能在huatuo中写出这样的代码并且正确运行的原因。

但泛型函数的共享规则远比泛型类的普通函数更复杂，因为clr支持神奇的泛型虚函数，如下例子

```c#

interface IFoo
{
    void Show<T>();
}

class FooImpl : IFoo
{
    
    public void Show<T>()
    {
        UnityEngine.Debug.Log(typeof(t));
    }
    
    public virtual void Run<T>()
    {
        UnityEngine.Debug.Log(default(T));
    }
    
    public void Fire<T>(T obj)
    {
        UnityEngine.Debug.Log(obj);
    }
}

```

例子中 Show&lt;T&gt; 是泛型接口函数。 Run&lt;T&gt;是普通泛型虚函数。

这些虚泛型函数又引发一个新的概念 RGCTX，机制复杂，这里不再展开讲述。但泛型虚函数，也是遵循相同的代码共享规则。

## 代码裁剪

由于unity默认的代码裁剪规则，如果你未在代码中使用过，它是不会为你生成这些reduce type的共享函数的。故为了让 List&lt;YourHotUpdateClass&gt; 能够正确运行。你要确保 List&lt;object&gt; （其实List&lt;string&gt;也行）必须在AOT中有正确的实例。

为了避免在脚本中不能使用List&lt;int&gt;或者List&lt;string&gt;，你得事先在AOT中使用或者引用过这些类型。感谢Generic Sharing，这些引用类不多。

为了方便大家使用，我们会提供一个默认的 RefTypes.cs 代码，它已经包含了对常见泛型类型的实例化。 你也可以自己填写或者扩充它。
