# 常见错误

## 如果调试时遇到transform函数处理 call指令时函数找不到的问题

这是unity代码裁剪引起的。你需要在主工程中显式带上类或者函数的使用，如RefTypes.cs所做的那样。

如果你是新使用huatuo的项目。建议将 [huatuo_trial](https://github.com/focus-creative-games/huatuo_trial)/Assets/Main/HuatuoLib 拷贝到你主工程，
然后再在RefTypes.cs里添加你要引用的类型。

## 调试时遇到 shareMethod-&gt;methodPointer断言错误

这是因为没有为相应的函数添加对应的泛型实例化。 在Debug工程(如何debug请看[源码跟踪与调试](source_inspect.md))中调试，查看函数名和类名。

## 遇到FileLoadException：xxxxxx/StreamingAssets/HotFix.dll 错误的问题

这是il2cpp原始代码里面抛出的，原因是在编译之前没有替换huatuo源码中的libil2cpp目录

解决办法：

  1. 确定已经替换了对应的Editor 中的libil2cpp 目录
  2. 删除Unity工程中的Library目录，重新构建即可

## Assembly.Load(byte[]) 出错: NotSupportedException

原因是你的huatuo太旧，未实现Load(byte[])这个函数。 拉最新的huatuo，替换你的libil2cpp，重新打包就行了

## 更新huatuo代码（替换libil2cpp）后发现更新未生效

这是由于之前使用过旧代码编译导致的，Library 是旧的。只要删掉Library在重新打包就可以了

## 打包生成Visual Studio Project后，编译出现错误找不到Windows SDK版本或无法打开.....\binUnityPlayerStub.lib

  打包生成的C++工程中，依赖关系为：项目主工程（同unity项目名，当前启动项目）依赖Il2CppOutputProject，Il2CppOutputProject依赖UnityPlayerStub。但是生成的工程设置中并没有设置依赖，一般按照下面的设置就能解决：

  1. 编译UnityPlayerStub项目，遇到问题就修改项目设置里面的 Windows SDK Version 和 Platform Toolset
  2. 编译Il2CppOutputProject 项目
  3. 启动成功

## 可以运行示例项目中的async task，但自己编译后却无法出现 shareMethod->methodPointer断言异常

原因是你使用了release编译，导致编译async时生成了值类型的状态机。在Unity Editor窗口最下面的状态栏，有一个臭虫按钮可以切换 Debug/Release，切换成Debug就可以了。

## 遇到  "This icall is not supported by il2cpp at System.AppDomain.Load"

有两种原因

1. 如果非ios平台，则因为未替换libil2cpp目录
2. 如果ios平台，因为ios平台并不从源码编译libil2cpp，而是使用随Editor打包的libil2cpp.a，你需要替换libil2cpp.a为huatuo的编译版本。

## 打包时遇到 static_assert(sizeof(il2cpp_array_size_t) == 8, "array size type == 8") 的错误

因为你build了32位程序。 huatuo当前只支持64位。

## 遇到提示Unity: TypeLoadException: Could not load type 'System.Object' from assembly 'netstandard'

原因是热更新部分的Api compatible level与主工程的不一致，热更新工程使用net standard而主工程使用.net 4.x(.net framework)。一般发生在你使用独立的vs工程而不是使用unity assembly def产生的。
解决办法为将热更新部分api compatible level切换为与主工程一致即可。

如果还发生错误，则删除Library目录，重新操作一次。

## 遇到提示Unity: TypeLoadException: Could not load type 'System.Object' from assembly 'mscorlib'

与上面的原因相似，主工程的api compatible level为 net standard而热更新工程使用.net 4.x或其他。

解决办法与上一条相同。
