
# 限制和注意事项

- 目前仅支持 2020.3.7f版本。 预计五月份后会支持 2018-2022 全系列版本。
- 无法创建出普通AOT泛型(**delegate、Nullable、数组(包括多维)不受限制，热更新泛型也完全不受限**)的**热更新非枚举值类型**的实例化类型的实例。 例如不支持List&lt;HotUpdateValueType&gt;但支持List&lt;int&gt;、List&lt;HotUpdateClass&gt;和List&lt;HotUpdateEnum&gt;。 具体原因见[AOT泛型限制及原理介绍](docs/generic_limit.md)。这个后续版本会基本解决。
- 暂时不支持返回**自定义值类型**的async task。原生值类型如int及枚举及class类型不受限制，原因同上。这个限制后续版本会解决。
- **注意使用link.xml或者代码引用的方式避免unity裁减代码。避免开发期能调用，发布后却找不到函数的错误**。我们后续会提供默认模板。
- 不支持delegate的BeginInvoke, EndInvoke。纯粹是觉得没必要实现。
- 由于Unity资源管理机制的限制（脚本uuid在打包时已确定，找不到热更新脚本对应的GUID），热更新的MonoBehaviour挂在scene或prefab中无法成功反序列化。但可以通过代码 go.AddComponent的方式挂载。通过一些自定义的script proxy加载的方式也是可以的。期望unity官方或者第三方出一个便利一些的解决方案。
- 暂不支持增量式gc。由于时间紧凑，来不及仔细处理增量式gc的memory barrier细节。这个问题很快会解决。
- 暂时不支持调试。但能打印错误堆栈（只能精确到函数）。