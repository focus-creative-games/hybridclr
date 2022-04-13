
# 限制和注意事项

**不在限制事项中的特性都是huatuo支持**。请不要再问huatuo是否支持某个功能。

- 支持2019-2022全系列版本，但不是每个小版本都支持。具体请查看[现在支持的Unity版本](support_versions.md)。
- 无法创建出普通AOT泛型(**delegate、Nullable、数组(包括多维)不受限制，热更新泛型也完全不受限**)的**热更新非枚举值类型**的实例化类型的实例。 例如不支持List&lt;HotUpdateValueType&gt;但支持List&lt;int&gt;、List&lt;HotUpdateClass&gt;和List&lt;HotUpdateEnum&gt;。 具体原因见[AOT泛型限制及原理介绍](generic_limit.md)。这个会在7月份版本比较彻底地解决，此后不再有限制。
- 暂时不支持返回**自定义值类型**的默认async task，原生值类型如int及枚举及class类型不受限制。原因是编译器会为async默认生成 AsyncTaskMethodBuilder&lt;T&gt;的泛型类实例化，如果像ETask那样使用自定义Task及AsyncTaskMethodBuilder，则不受限制。原生async这个限制后续版本会解决。
- **注意使用link.xml或者代码引用的方式避免unity裁减代码。避免开发期能调用，发布后却找不到函数的错误**。我们后续会提供默认模板。
- 不支持delegate的BeginInvoke, EndInvoke。纯粹是觉得没必要实现。
- 在资源中挂载热更新脚本需要在打包时做少量特殊处理，参见[MonoBehaviour相关工作流](./MonoBehaviour.md)
- 暂不支持增量式gc。由于时间紧凑，来不及仔细处理增量式gc的memory barrier细节。这个问题很快会解决。
- 暂时不支持打包后真机的c#源码调试，但能打印错误堆栈（只能精确到函数），也可以在Build出的Debug工程中跟踪调试。Editor下开发期调试使用平时的mono调试就可以了。
