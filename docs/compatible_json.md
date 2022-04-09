# 兼容性报告

测试了常见的框架与库，以下是相应的兼容性测试结果。

无论哪个框架和库，都必然有huatuo对AOT泛型的限制问题，测试这些框架时，不再考虑违背这种公共限制的情况，
只给出额外的不兼容性。

测试用的类型附在最后一节。

## NewtonsoftJson

[NewtonsoftJson](https://github.com/jilleJr/Newtonsoft.Json-for-Unity)。额外安装了 [Newtonsoft.Json-for-Unity.Converters](https://github.com/jilleJr/Newtonsoft.Json-for-Unity.Converters)

结论: 兼容性高。相对于原生情况下的使用，除了标准的AOT泛型限制外基本没有增加额外限制。

### 测试结果

- 对于普通class类型，完全不受限
- 对于容器类型，需要使用AOTHelper来提前注册（与unity之前使用NewtonsoftJson的限制相同）
- 对于值类型（无论泛型还是非泛型、无论AOT还是解释部分）
  - Serialize完全不受限
  - Deserialize&lt;T&gt; 如果未用AotHelper.EnsureType&lt;T&gt;注册过，则无法使用。根源还是AOT函数受限
  - Deserialize&lt;T&gt;(string json, Type type) 不受限
  - 值类型作为成员字段不受限

### 使用注意事项

 但由于AOT限制，对于array和容器类型，需要提前使用 AotHelper.EnsureList&lt;T&gt;、AotHelper.EnsureDictionary&lt;K,V&gt;来确保NewtonsoftJson有相应的处理函数。

```c#
    AotHelper.EnsureList<int>();
    AotHelper.EnsureList<long>();
    AotHelper.EnsureList<float>();
    AotHelper.EnsureList<double>();
    AotHelper.EnsureList<string>();
    AotHelper.EnsureDictionary<int, int>();
    AotHelper.EnsureDictionary<int, string>();
```

## CatJson

[CatJson](https://github.com/CatImmortal/CatJson)

结论：兼容性极佳，只要不违背AOT限制就能工作。使用比NewtonsoftJson简单，不需要提升使用AotHelper.Ensure来确保容器能正常工作。

## litjson

[litjson](https://github.com/LitJSON/litjson)。推荐基于Unity的扩展和改造版本[LitJson4Unity](https://github.com/XINCGer/LitJson4Unity )

测试结论：兼容性无大问题，但litjson本身使用体验太差。有以下一些问题

- 值类型如UnityEngine.Vector2 需要手动注册相应的Exporter和Importer
- 不支持Dictionary类型，需要手动注册相应的Exporter和Importer

**===强烈不推荐==** 在huatuo下使用litjson。

## Utf8Json

[Utf8Json](https://github.com/neuecc/Utf8Json)

结论：原始代码(utf8json的unity package 版本)完全不兼容il2cpp，不建议使用。修改完不兼容的代码后能在il2cpp下正常运行，仍然完全无法支持class中包含热更新ValueType类型，无论是直接或者通过容器间接包含。相比于其他方案限制最大。

1. Utf8Json的unity版本DynamicObject相关Formatter和Resolvers使用了DynamicAssembly，此特性与il2cpp完全不兼容，因为il2cpp没实现这些代码。
2. 即使注释掉DynamicObject相关代码，仍然由于IJsonFormatterResolver.GetFormatter&lt;T&gt;是AOT泛型函数，完全无法支持自定义热更新类型
3. 即使不使用热更新值类型，utf8json要求注册ArrayFormatter&lt;T&gt;、List&lt;T&gt;等等泛型AOT实例化，以及IJsonFormatter&lt;T&gt;.Serialize及.Deserialize的实例化，导致实际使用体验相当差，需要较多AOT注册。

## 测试类型

```c#
enum ProduceType
{
    A,
    B,
}

struct IntVector
{
    public int X { get; set; }

    public int Y { get; set; }

    public int z;
}

class Pair
{
    public int A { get; set; }

    public string B;
}

class Product
{
    public bool X1 { get; set; }

    public byte X2 { get; set; }

    public char X2_1 { get; set; }

    public sbyte X3 { get; set; }

    public short X4 { get; set; }

    public ushort X5 { get; set; }

    public int X6 { get; set; }

    public uint X7 { get; set; }

    public long X8 { get; set; }

    public ulong X9 { get; set; }

    public float X10 { get; set; }

    public double X11 { get; set; }

    public decimal X12 { get; set; }

    public string A1 { get; set; }

    public ProduceType A2 { get; set; }

    public System.IO.FileAccess A3 { get; set; }

    public Vector2 A4 { get; set; }

    public Vector3 A5 { get; set; }

    public Vector4 A6 { get; set; }

    public IntVector A7 { get; set; }

    public Pair A8 { get; set; }

    public DateTime A9 { get; set; }

    public int[] B1 { get; set; }

    public string[] B2 { get; set; }

    public List<int> C1 { get; set; }

    public List<string> C2 { get; set; }

    public HashSet<int> D1 { get; set; }

    public HashSet<string> D2 { get; set; }

    public Dictionary<int, int> E1 { get; set; }

    public Dictionary<int, string> E2 { get; set; }

}
```
