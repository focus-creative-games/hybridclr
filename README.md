
# HybridCLR

[![license](http://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/focus-creative-games/hybridclr/blob/main/LICENSE)

![logo](./docs/images/logo.jpg)

<br/>
<br/>

HybridCLR(代号wolong)是一个**特性完整、零成本、高性能、低内存**的**近乎完美**的Unity全平台原生c#热更方案。

HybridCLR扩充了il2cpp的代码，使它由纯[AOT](https://en.wikipedia.org/wiki/Ahead-of-time_compilation) runtime变成‘AOT+Interpreter’ 混合runtime，进而原生支持动态加载assembly，使得基于il2cpp backend打包的游戏不仅能在Android平台，也能在IOS、Consoles等限制了JIT的平台上高效地以**AOT+interpreter**混合模式执行。从底层彻底支持了热更新。

## 文档

- [官方文档](https://focus-creative-games.github.io/hybridclr/index/)
- [快速上手](https://focus-creative-games.github.io/hybridclr/start_up/)
- [示例项目](https://github.com/focus-creative-games/hybridclr_trial)
- [知乎专栏](https://www.zhihu.com/column/c_1489549396035870720)
- [UWA学堂](https://edu.uwa4d.com/course-intro/0/432)

## 特性

- 特性完整。 近乎完整实现了[ECMA-335规范](https://www.ecma-international.org/publications-and-standards/standards/ecma-335/)，除了 下文中"限制和注意事项" 之外的特性都支持。
- 零学习和使用成本。 HybridCLR将纯AOT runtime增强为完整的runtime，使得热更新代码与AOT代码无缝工作。脚本类与AOT类在同一个运行时内，可以随意写继承、反射、多线程(volatile、ThreadStatic、Task、async)之类的代码。不需要额外写任何特殊代码、没有代码生成，也没有什么特殊限制。
- 执行高效。实现了一个极其高效的寄存器解释器，所有指标都大幅优于其他热更新方案。[性能测试报告](https://focus-creative-games.github.io/hybridclr/benchmark/#性能测试报告)
- 内存高效。 热更新脚本中定义的类跟普通c#类占用一样的内存空间，远优于其他热更新方案。[内存占用报告](https://focus-creative-games.github.io/hybridclr/benchmark/#内存占用报告)
- 原生支持hotfix修复AOT部分代码。几乎不增加任何开发和运行开销。

## 工作原理

HybridCLR从mono的[hybrid mode execution](https://developpaper.com/new-net-interpreter-mono-has-arrived/)技术中得到启发，为unity的il2cpp之类的AOT runtime额外提供了interpreter模块，将它们由纯AOT运行时改造为"AOT + Interpreter"混合运行方式。

![icon](docs/images/architecture.png)

更具体地说，HybridCLR做了以下几点工作：

- 实现了一个高效的元数据(dll)解析库
- 改造了元数据管理模块，实现了元数据的动态注册
- 实现了一个IL指令集到自定义的寄存器指令集的compiler
- 实现了一个高效的寄存器解释器
- 额外提供大量的instinct函数，提升解释器性能
- 提供hotfix AOT的支持

## 与其他流行的c#热更新方案的区别

### 本质比较

HybridCLR是原生的c#热更新方案。通俗地说，il2cpp相当于mono的aot模块，HybridCLR相当于mono的interpreter模块，两者合一成为完整mono。HybridCLR使得il2cpp变成一个全功能的runtime，原生（即通过System.Reflection.Assembly.Load）支持动态加载dll，从而支持ios平台的热更新。

正因为HybridCLR是原生runtime级别实现，热更新部分的类型与主工程AOT部分类型是完全等价并且无缝统一的。可以随意调用、继承、反射、多线程，不需要生成代码或者写适配器。

其他热更新方案则是独立vm，与il2cpp的关系本质上相当于mono中嵌入lua的关系。因此类型系统不统一，为了让热更新类型能够继承AOT部分类型，需要写适配器，并且解释器中的类型不能为主工程的类型系统所识别。特性不完整、开发麻烦、运行效率低下。

### 实际使用体验或者特性比较

- 学习和使用成本几乎为零。HybridCLR让il2cpp变成全功能的runtime，学习和使用成本几乎为零，几乎零侵入性。而其他方案则有大量的坑和需要规避的规则，学习和使用成本，需要对原项目作大量改造。
- 可以使用所有c#的特性。而其他方案往往有大量的限制。
- 可以直接支持使用和继承主工程中的类型。其他方案要写适配器或者生成代码。
- 热更新部分元数据与AOT元数据无缝统一。像反射代码能够正常工作的，AOT部分也可以通过标准Reflection接口创建出热更新对象。其他方案做不到。
- 对多线程支持良好。像多线程、ThreadStatic、async等等特性都是HybridCLR直接支持，其他方案除了async特性外均难以支持。
- Unity工作流与原生几乎完全相同。HybridCLR中热更新MonoBehaviour可以直接挂载在热更新资源上，并且正确工作。其他方案不行。
- 兼容性极高。各种第三方库只要在il2cpp下能工作，在HybridCLR下也能正常工作。其他方案往往要大量魔改源码。
- 内存效率极高。HybridCLR中热更新类型与主工程的AOT类型完全等价，占用一样多的空间。其他方案的同等类型则是假类型，不仅不能被runtime识别，还多占了数倍空间。
- 执行效率高。HybridCLR中热更新部分与主工程AOT部分交互属于il2cpp内部交互，效率极高。而其他方案则是独立虚拟机与il2cpp之间的效率，不仅交互麻烦还效率低下。


## 兼容性

- 支持所有il2cpp支持的平台。目前测试支持 PC(Win32和Win64)、macOS(x86、x64、Arm64)、Android(armv7、armv8)、iOS(64bit)、NS(64bit)、WebGL(有少量bug)平台，剩余平台有待测试。
- 已经支持Unity 2020-2021全系列LTS版本，预计于2022.8月上旬支持 2019全系列LTS版本
- 测试过大量游戏常见库，未发现跟il2cpp原生兼容但使用HybridCLR后不兼容性的库。只要能在il2cpp backend下工作的库都可以在HybridCLR下正常工作。甚至那些与il2cpp因为AOT问题不兼容的库，现在因为HybridCLR对il2cpp的能力扩充，反而可以正常运行了。

## 稳定性状况

目前PC(x86及x64)、macOS(x86、x64、Arm64)、Android(arm v7及v8)、iOS(64bit) 可稳定使用。已经有几十个大中型游戏项目较完整地接入，其中一些在紧锣密鼓作上线前测试。

鉴于在多个重度上线（准上线）项目上有超过2个月的稳定表现，预计于**8月份发布正式版本**。

## 接入的商业项目

- 2022.6.7上线第一款Android+iOS双端三消类型游戏
- 2022.8.5上线第二款双端重度RPG卡牌
- 2022.8.8上线第三款双端重度RPG塔防游戏 
- 2022.8 还有至少3款：MMORPG（重度）、RPG塔防（中度）、三消（中度）上线
- 其他参见收集的一些 [完整接入的商业项目列表](https://focus-creative-games.github.io/hybridclr/ref_project/)

## 支持与联系

- QQ群：651188171 HybridCLR(wolong)技术交流群 **(官方主群)**。可以反馈bug，但**不要在群里咨询基础使用问题**。
- QQ群：428404198 HybridCLR(wolong)新手群 **(新手群)**。新手使用过程中遇到问题，都可以在群里咨询。
- 邮箱：hybridclr@focus-creative-games.com

## RoadMap

HybridCLR虽然与il2cpp相关，但绝大多数核心代码独立于il2cpp，很容易移植（预计一个月）到其他不支持AOT+Interpreter的CLR平台。无论unity如何版本变迁，哪怕废弃了il2cpp改用.net 6+，HybridCLR会持续跟进，稳定地提供跨平台的CLR热更新服务，直至某天.net官方直接支持AOT+Interpreter，则HybridCLR完成其历史使命。

- 正式支持Unity 2019LTS全系列版本 (2022.7 - 2022.8)
- 支持 `Hybrid Dll` 技术 (2022.9)
- 指令优化，编译后指令数减少到原来1/4-1/2，基础指令和大多数对象模型指令有100%-300%的性能提升。 (2022.10 -)
- 支持增量式GC (2022.10 -)

## 关于作者

**walon** ：**focus-creative-games** 创始人

毕业于清华大学物理系，2006年CMO金牌，奥数国家集训队成员，保送清华基科班。专注于游戏技术，擅长开发架构和基础技术设施。

## 赞助

我们为开发HybridCLR投入巨量人力及其他资源，你们的赞助如同雪中送炭会让我们坚持下来，并且让我们做得更快更好。感谢热心慷慨的你们！

**微信**

![weixin](./docs/sponsor/weixin.JPG)

**支付宝**

![zhifubao](./docs/sponsor/zhifubao.JPG)

## license

HybridCLR is licensed under the [MIT](https://github.com/focus-creative-games/hybridclr/blob/main/LICENSE) license
