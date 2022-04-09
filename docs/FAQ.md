# FAQ

## huatuo支持哪些平台?

il2cpp支持的平台都支持

## huatuo是嵌了mono吗？

不是。huatuo给il2cpp补充了完全独立自主实现的完整的寄存器解释器。

## huatuo写代码有什么限制吗？

除了以下明确不支持的，剩余特性都是支持的：

- AOT泛型有少量限制外（参见泛型文档）
- 不支持delegate的BeginInvoke和EndInvoke函数。无用，故意不支持。
- 不支持extern 函数 (后面会支持)

## 泛型类有什么限制?

无法创建出普通AOT泛型(**delegate、Nullable、数组(包括多维)不受限制，热更新泛型也完全不受限**)的**热更新非枚举值类型**的实例化类型的实例。 例如不支持List&lt;HotUpdateValueType&gt;但支持List&lt;int&gt;、List&lt;HotUpdateClass&gt;和List&lt;HotUpdateEnum&gt;。

## 支持热更新部分的泛型类和泛型函数吗？

彻底完整的支持，无任何限制。

## 支持热更新值类型的数组类型吗，如 MyHotUpdateValueType[]？

支持，无任何限制，任何维都可以。

## 支持多维数组吗？

支持，无任何限制。

## 支持可空变量吗？

完整支持，无任何限制。

## 支持热更新MonoBehaviour吗？

支持。但由于unity资源管理的问题，只能手动go.AddComponent&lt;T&gt;添加。 如果能解决unity资源加载的 guid问题（比如允许动态更新这些信息），则可以彻底解决。

## 支持反射吗？

支持， 无任何限制。

## 对多线程支持如何？

完整支持。 支持Thread, Task, volatile, ThreadStatic, async（部分受限）。

## 支持async task吗？

支持。但只支持 返回原生类型或者class类型。 如 Task&lt;int&gt;， Task&lt;YourHotUpdateClassType&gt;

## 支持多Assembly吗？

支持。但是不会自动加载依赖dll。需要你手动按依赖顺序加载热更dll。

## 支持IEnumerator吗?

支持。

## 继承AOT类需要写什么adaptor之类的代码吗？

huatuo是特性完整的运行时。不需要写任何额外的代码，随便继承。

## 支持创建值类型吗？

支持。

## 支持注解吗？

支持。

## 支持调试吗？

暂时不支持。但当前能打印调用堆栈。
