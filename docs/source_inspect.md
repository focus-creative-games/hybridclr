
# huatuo源码结构及调试

## huatuo模块介绍

huatuo是基于unity il2cpp运行时的扩展。为了将il2cpp由AOT扩展为AOT+interpreter的混合模式，huatuo实现了以下功能：

- c++实现的dll解析库
- 元数据注册。由于il2cpp是静态AOT，原始代码并不支持动态注册，因为做了少量修改（几百行）
- 指令集转换。将原始IL指令转成更高效的寄存器指令
- 寄存器解释器。实现了一个高效的解释器。

目录结构上，与之对应：

- huatuo 自身源码
  - interpreter 解释器模块
  - metadata 元数据解析与注册模块
  - transform 指令集转换模块
- 对il2cpp源码的修改

    huatuo对il2cpp源码修改主要为支持动态注册元数据。大多数地方只是插入了hook处理，并未修改原始实现。例如:

```cpp
const char* il2cpp::vm::GlobalMetadata::GetStringFromIndex(StringIndex index)
{
    // ==={{ huatuo
    if (huatuo::metadata::IsInterpreterIndex(index))
    {
        return huatuo::metadata::MetadataModule::GetStringFromEncodeIndex(index);
    }
    // ===}} huatuo

    IL2CPP_ASSERT(index <= s_GlobalMetadataHeader->stringCount);
    const char* strings = ((const char*)s_GlobalMetadata + s_GlobalMetadataHeader->stringOffset) + index;
    return strings;
}
```

huatuo大约只改动了几百行这种简单的hook代码。后续迁移和维护到新的il2cpp版本是比较简单的事情。

## 调试

huatuo解释器核心工作包括两部分：

- 指令集转换。将基于栈的IL指令转换为基于寄存器的版本。在 huatuo/transform/transform.cpp 的 HiTransform::Transform函数。
- 寄存器指令的解释执行。在 huatuo/interpreter/interpreter_Execute.cpp的 Interpreter::Execute函数。

只要断点到这两个函数，就很容易逐步跟踪IL函数的转换转换到解决执行的整个流程。

### 创建测试工程

- 准备 Unity 2020.3.7 版本。根据你的平台必须同时安装相应的il2cpp模块。
- Project Settings 设置
  - Scripting Backend 为 IL2Cpp
  - C++ Compiler Configuration 为 Debug
- Building Settings 。选中 "Create VisualStudio Solution"，发布完即包含一个源码工程，可供测试。
- Build完成后，即产生一个可调试的工程

### transform 实现简介

跟常规的指令树分析非常相似。分为几部分

- BasicBlock划分。将原始IL指令切分为多个BasicBlock，每个BasicBlock不包含任何跳转函数。这么做可以比较高效地避免意外的跨跳块的指令合并
- 模拟执行所有逻辑分支，包括跳转和异常分支，将每个IL指令转换为对应寄存器指令。
- 指令优化（待做）。预计于下个月版本开始开发。届时大多数指令可以获得100-300%的性能提升。

### interpreter 实现简介

比较直接。就是解释执行指令。huatuo已经实现了解释器栈的复用。脚本函数的嵌套调用不需要发生解释器函数的嵌套，另外也省去了参数栈的多次复制，大幅优化了调用成本（调用AOT函数则无法规避这个成本）。

异常机制和函数的嵌套调用，大家自己看源码吧。暂时不多解释了。
