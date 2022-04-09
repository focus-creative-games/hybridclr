# 兼容性报告

测试了常见的框架与库，以下是相应的兼容性测试结果。

无论哪个框架和库，都必然有huatuo对AOT泛型的限制问题，测试这些框架时，不再考虑违背这种公共限制的情况，
只给出额外的不兼容性。

## json库

由于常用的json库较多，json的兼容性测试单独给一个[json测试报告](compatible_json.md)

- [NewtonsoftJson](https://github.com/jilleJr/Newtonsoft.Json-for-Unity) 兼容性佳，与原生使用注意事项相同，需要使用AotHelper提前确保使用
- [CatJson](https://github.com/CatImmortal/CatJson) 兼容性极佳，只要不违背AOT限制就能工作。 **最佳推荐**
- [litjson](https://github.com/LitJSON/litjson) 兼容性佳，与Newtonsoft相似，但需要写较多类型注册器，较为繁琐
- [utf8json](https://github.com/neuecc/Utf8Json) 过于追求性能，原版unity package与il2cpp完全不兼容。改造后可兼容，但使用较不便。**不推荐**。

## protobuf库

### protobuf-net

[github](https://github.com/protobuf-net/protobuf-net). 版本 2.4.1

结论：兼容性一般

注意事项：

- Dictionary 无法使用，这个问题纯AOT下也存在，非huatuo问题。因为MapDecorator是internal，无法提前构造AOT的泛型实例。如果非要用，解决办法是修改源码，改成public，然后再提前构造它的泛型实例化类型

### protobuf 官方

- protobuf 官方实现

[github](https://github.com/protocolbuffers/protobuf).  版本 3.19.4

结论：兼容性佳。

注意事项：

- map类型需要提前注册 MapField&lt;K&gt;&lt;V&gt;及MapField&lt;K&gt;&lt;V&gt;.Codec。

### SQLite4Unity3d

[github](https://github.com/robertohuertasm/SQLite4Unity3d)

结论：兼容性一般，但常见操作均能正常工作。

- New Database、CreateTable 正常
- Insert、Get、Delete正常
- 遍历Table正常
- 对Table执行Where之类Linq语句无法工作（在mono下就已经无法工作，应该是它自身的bug）

## MongoDB.Bson

[官方链接](http://mongodb.github.io/mongo-java-driver/3.4/bson/) ，测试使用2.15.0版本

结论：完全兼容

注意事项：

- 需要在AOT中提前注册的类型较多
  - IBsonSerializer&lt;object&gt;
  - EnumSerializer&lt;IntEnum&gt;
  - ArraySerializer&lt;T&gt;
  - EnumerableInterfaceImplementerSerializer&lt;List&lt;T&gt;,T&gt;
  - DictionaryInterfaceImplementerSerializer&lt;Dictionary&lt;K,V&gt;,K,V&gt;
  - 其他需要注册的
- Serializer注册。
  - 不需要在AOT中提前注册，在热更新模块中注册同样可以工作。
  - 对于值类型的自定义BsonSerializer，如果在热更新部分注册，由于泛型AOT限制，需要从IBsonSerializer&lt;T&gt;实现，而不能从SerializerBase&lt;T&gt;继承。对于class类型则无限制。

## DOTween

[官方链接](http://dotween.demigiant.com/index.php) 版本 1.2.632

结论：极高的兼容性，只有DOTween.To&lt;&gt;接口有一定的AOT泛型限制问题。

注意事项：

- DOTween.To&lt;&gt; 这个泛型接口由于约束了TPlugOptions泛型参数必须为值类型，导致要求这个参数对应的类型必须为AOT泛型值类型。

## UniTask

[github](https://github.com/Cysharp/UniTask)

结论：兼容性高。限制与普通async完全相同，只需要提前注册相应的aot泛型实例。

注意事项：

由于UniTask支持异步模式的较多，因此要注册的Awaiter类型也较多，需要仔细添加上相应AOT泛型实例化。

## FairyGUI

[github](https://github.com/fairygui/FairyGUI-unity) 最新版本。

结论：兼容性极佳。

## GameFramework

[github](https://github.com/EllanJiang/GameFramework) 最新版本。

结论：兼容性极佳。

## ET

[github](https://github.com/egametang/ET) 最新版本

结论：兼容性高。 ETask有类似async Task的AOT泛型限制。但如果把ETask全部移到热更新层，则完全无限制。
