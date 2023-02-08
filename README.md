
# HybridCLR

[![license](http://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/focus-creative-games/hybridclr/blob/main/LICENSE)

![logo](./docs/images/logo.jpg)

<br/>
<br/>

HybridCLR是 focus-creative-games（代码哲学） 公司的代表作品，我们希望通过我们的聪明才智深刻地改变整个行业，帮助游戏团队制作出更优秀的游戏。

HybridCLR是一个**特性完整、零成本、高性能、低内存**的**近乎完美**的Unity全平台原生c#热更方案。

HybridCLR扩充了il2cpp的代码，使它由纯[AOT](https://en.wikipedia.org/wiki/Ahead-of-time_compilation) runtime变成‘AOT+Interpreter’ 混合runtime，进而原生支持动态加载assembly，使得基于il2cpp backend打包的游戏不仅能在Android平台，也能在IOS、Consoles等限制了JIT的平台上高效地以**AOT+interpreter**混合模式执行，从底层彻底支持了热更新。

HybridCLR不仅支持传统的全解释执行模式，还开创性地实现了 `Differential Hybrid Execution(DHE)` 差分混合执行技术。即可以对AOT dll任意增删改，会智能地让变化或者新增的类和函数以interpreter模式运行，但未改动的类和函数以AOT方式运行，让热更新的游戏逻辑的运行性能基本达到原生AOT的水平。

欢迎拥抱现代原生C#热更新技术 ！！！

## 文档

- [官方文档](https://focus-creative-games.github.io/hybridclr/about/)
- [技术论坛](https://forum.focus-creative-games.com/topics)
- [快速上手](https://focus-creative-games.github.io/hybridclr/start_up/)
- [示例项目](https://github.com/focus-creative-games/hybridclr_trial)
- [知乎专栏](https://www.zhihu.com/column/c_1489549396035870720)
- [UWA学堂](https://edu.uwa4d.com/course-intro/0/432)

## 特性

- 特性完整。 近乎完整实现了[ECMA-335规范](https://www.ecma-international.org/publications-and-standards/standards/ecma-335/)，除了[限制事项](https://focus-creative-games.github.io/hybridclr/limit/)之外的特性都支持。
- 零学习和使用成本。 HybridCLR将纯AOT runtime增强为完整的runtime，使得热更新代码与AOT代码无缝工作。脚本类与AOT类在同一个运行时内，可以随意写继承、反射、多线程(volatile、ThreadStatic、Task、async)之类的代码。不需要额外写任何特殊代码、没有代码生成，几乎没有限制。
- 执行高效。实现了一个极其高效的寄存器解释器，所有指标都大幅优于其他热更新方案。[性能测试报告](https://focus-creative-games.github.io/hybridclr/performance)
- 内存高效。 热更新脚本中定义的类跟普通c#类占用一样的内存空间，远优于其他热更新方案。[内存占用报告](https://focus-creative-games.github.io/hybridclr/memory)
- 由于对泛型的完美支持，使得因为AOT泛型问题跟il2cpp不兼容的库现在能够完美地在il2cpp下运行
- 支持一些il2cpp不支持的特性，如__makeref、 __reftype、__refvalue指令
- `Differential Hybrid Execution(DHE)` 差分混合执行技术

## 工作原理

HybridCLR从mono的 [mixed mode execution](https://www.mono-project.com/news/2017/11/13/mono-interpreter/) 技术中得到启发，为unity的il2cpp之类的AOT runtime额外提供了interpreter模块，将它们由纯AOT运行时改造为"AOT + Interpreter"混合运行方式。

![icon](docs/images/architecture.png)

更具体地说，HybridCLR做了以下几点工作：

- 实现了一个高效的元数据(dll)解析库
- 改造了元数据管理模块，实现了元数据的动态注册
- 实现了一个IL指令集到自定义的寄存器指令集的compiler
- 实现了一个高效的寄存器解释器
- 额外提供大量的instinct函数，提升解释器性能

## 与其他流行的c#热更新方案的区别

HybridCLR是原生的c#热更新方案。通俗地说，il2cpp相当于mono的aot模块，HybridCLR相当于mono的interpreter模块，两者合一成为完整mono。HybridCLR使得il2cpp变成一个全功能的runtime，原生（即通过System.Reflection.Assembly.Load）支持动态加载dll，从而支持ios平台的热更新。

正因为HybridCLR是原生runtime级别实现，热更新部分的类型与主工程AOT部分类型是完全等价并且无缝统一的。可以随意调用、继承、反射、多线程，不需要生成代码或者写适配器。

其他热更新方案则是独立vm，与il2cpp的关系本质上相当于mono中嵌入lua的关系。因此类型系统不统一，为了让热更新类型能够继承AOT部分类型，需要写适配器，并且解释器中的类型不能为主工程的类型系统所识别。特性不完整、开发麻烦、运行效率低下。

## 兼容性

- 支持2019.4.x、2020.3.x、2021.3.x系列LTS版本
- 支持所有il2cpp支持的平台。目前已完善支持 PC(Win32和Win64)、macOS(x86、x64、Arm64)、Android(armv7、armv8)、iOS(64bit)、WebGL、**微信小程序平台**，剩余平台有待测试。
- 测试过大量游戏常见库，未发现跟il2cpp原生兼容但使用HybridCLR后不兼容性的库。只要能在il2cpp backend下工作的库都可以在HybridCLR下正常工作。甚至那些与il2cpp因为AOT问题不兼容的库，现在因为HybridCLR对il2cpp的能力扩充，反而可以正常运行了。

## 稳定性状况

当前已经发布了稳定完善的**1.0**正式版本，足以满足大中型商业项目的稳定性要求。自2022.6.7上线第一个游戏起，线上项目中只发生过一起小bug，并且迅速地在几个小时内被修复。

目前至少有数百个商业游戏项目完成接入，其中有几十个已经双端上线，上线的项目中包括MMORPG、重度卡牌、重度塔防之类的游戏。很多大家熟知的头部公司也已经接入多个项目并且很快就要上线。

## 支持与联系

- QQ官方1群：651188171（满）。可以反馈bug，但**不要在群里咨询基础使用问题**。
- QQ官方2群：680274677（新）。可以反馈bug，但**不要在群里咨询基础使用问题**。
- QQ新手1群：428404198。新手使用过程中遇到问题，都可以免费在群里咨询。
- **QQ悬赏互助群**：762953653。悬赏提问，快速解决问题。
- 官方邮箱：hybridclr@focus-creative-games.com
- [商业化支持](https://focus-creative-games.github.io/hybridclr/price/)

## 后续开发规划

- 解释器指令优化
- 支持增量式GC
- 支持extern函数
- 其他优化

## 关于作者

**walon** ：**focus-creative-games** 创始人

毕业于清华大学物理系，2006年CMO金牌，奥数国家集训队成员，保送清华基科班。专注于游戏技术，擅长开发架构和基础技术设施。

## license

HybridCLR is licensed under the [MIT](https://github.com/focus-creative-games/hybridclr/blob/main/LICENSE) license
