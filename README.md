
# huatuo

[![license](http://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/focus-creative-games/huatuo/blob/main/LICENSE)

<br/>

![icon](docs/images/logo.png)

<br/>

huatuo是一个**特性完整、零成本、高性能、低内存**的**近乎完美**的Unity全平台原生c#热更方案。

huatuo扩充了il2cpp的代码，使它由纯[AOT](https://en.wikipedia.org/wiki/Ahead-of-time_compilation) runtime变成‘AOT+Interpreter’ 混合runtime，进而原生支持动态加载assembly，使得基于il2cpp backend打包的游戏不仅能在Android平台，也能在IOS、Consoles等限制了JIT的平台上高效地以**AOT+interpreter**混合模式执行。从底层彻底支持了热更新。

huatuo**开创性地实现了 `differential hybrid dll` 技术**====。即可以对AOT dll任意增删改，huatuo会智能地让变化或者新增的类和函数以interpreter模式运行，但未改动的类和函数以AOT方式运行，让热更新的游戏逻辑的运行性能基本达到原生AOT的水平。

## 特性

- 特性完整。 近乎完整实现了[ECMA-335规范](https://www.ecma-international.org/publications-and-standards/standards/ecma-335/)，除了 下文中"限制和注意事项" 之外的特性都支持。
- 零学习和使用成本。 huatuo将纯AOT runtime增强为完整的runtime，使得热更新代码与AOT代码无缝工作。脚本类与AOT类在同一个运行时内，可以随意写继承、反射、多线程(volatile、ThreadStatic、Task、async)之类的代码。不需要额外写任何特殊代码、没有代码生成，也没有什么特殊限制。
- 执行高效。实现了一个极其高效的寄存器解释器，所有指标都大幅优于其他热更新方案。[性能测试报告](https://focus-creative-games.github.io/huatuo/performance/benchmark/#性能测试报告)
- 内存高效。 热更新脚本中定义的类跟普通c#类占用一样的内存空间，远优于其他热更新方案。[内存占用报告](https://focus-creative-games.github.io/huatuo/performance/benchmark/#内存占用报告)
- 原生支持hotfix修复AOT部分代码。几乎不增加任何开发和运行开销。
- **开创性地实现了 `differential hybrid dll` 技术**。即可以将某个热更新dll先AOT形式打包，后面可以对该dll任意增删改，huatuo会智能地让变化或者新增的类和函数以interpreter模式运行，但未改动的类和函数以AOT方式运行。这意味着热更新的游戏逻辑的运行性能将接近原生AOT的水平。

## 工作原理

huatuo从mono的[hybrid mode execution](https://developpaper.com/new-net-interpreter-mono-has-arrived/)技术中得到启发，为unity的il2cpp之类的AOT runtime额外提供了interpreter模块，将它们由纯AOT运行时改造为"AOT + Interpreter"混合运行方式。

![icon](docs/images/architecture.png)

更具体地说，huatuo做了以下几点工作：

- 实现了一个高效的元数据(dll)解析库
- 改造了元数据管理模块，实现了元数据的动态注册
- 实现了一个IL指令集到自定义的寄存器指令集的compiler
- 实现了一个高效的寄存器解释器
- 额外提供大量的instinct函数，提升解释器性能
- 提供hotfix AOT的支持

## 与其他流行的c#热更新方案的区别

### 本质比较

huatuo是原生的c#热更新方案。通俗地说，il2cpp相当于mono的aot模块，huatuo相当于mono的interpreter模块，两者合一成为完整mono。huatuo使得il2cpp变成一个全功能的runtime，原生（即通过System.Reflection.Assembly.Load）支持动态加载dll，从而支持ios平台的热更新。

正因为huatuo是原生runtime级别实现，热更新部分的类型与主工程AOT部分类型是完全等价并且无缝统一的。可以随意调用、继承、反射、多线程，不需要生成代码或者写适配器。

其他热更新方案则是独立vm，与il2cpp的关系本质上相当于mono中嵌入lua的关系。因此类型系统不统一，为了让热更新类型能够继承AOT部分类型，需要写适配器，并且解释器中的类型不能为主工程的类型系统所识别。特性不完整、开发麻烦、运行效率低下。

### 实际使用体验或者特性比较

- huatuo学习和使用成本几乎为零。huatuo让il2cpp变成全功能的runtime，学习和使用成本几乎为零，几乎零侵入性。而其他方案则有大量的坑和需要规避的规则，学习和使用成本，需要对原项目作大量改造。
- huatuo可以使用所有c#的特性。而其他方案往往有大量的限制。
- huatuo中可以直接支持使用和继承主工程中的类型。其他方案要写适配器或者生成代码。
- huatuo中热更新部分元数据与AOT元数据无缝统一。像反射代码能够正常工作的，AOT部分也可以通过标准Reflection接口创建出热更新对象。其他方案做不到。
- huatuo对多线程支持良好。像多线程、ThreadStatic、async等等特性都是huatuo直接支持，其他方案除了async特性外均难以支持。
- huatuo中Unity工作流与原生几乎完全相同。huatuo中热更新MonoBehaviour可以直接挂载在热更新资源上，并且正确工作。其他方案不行。
- huatuo兼容性极高。各种第三方库只要在il2cpp下能工作，在huatuo下也能正常工作。其他方案往往要大量魔改源码。
- huatuo内存效率极高。huatuo中热更新类型与主工程的AOT类型完全等价，占用一样多的空间。其他方案的同等类型则是假类型，不仅不能被runtime识别，还多占了数倍空间。
- huatuo执行效率高。huatuo中热更新部分与主工程AOT部分交互属于il2cpp内部交互，效率极高。而其他方案则是独立虚拟机与il2cpp之间的效率，不仅交互麻烦还效率低下。

## 文档

- [文档站](https://focus-creative-games.github.io/)，**推荐使用**
- [FAQ](https://focus-creative-games.github.io/huatuo/faq/)
- [限制和注意事项](https://focus-creative-games.github.io/huatuo/performance/limit/)
- [示例项目](https://github.com/focus-creative-games/huatuo_trial)
- [知乎专栏](https://www.zhihu.com/column/c_1489549396035870720)
- [==>致谢名单<==](https://focus-creative-games.github.io/huatuo/donate/)

## 稳定性状况

=== **庆祝于 2021.6.7 第一款使用huatuo的android和iOS双端休闲游戏正式上线** ===，7月份还有几款中重游戏上线或者对外测试。

技术评估上目前稳定性处于Beta版本。由于huatuo技术原理的先进性，bug本质上不多，稳定得非常快。

- 目前PC、Android、iOS 已跑通所有单元测试，可稳定体验使用。
- 测试了游戏常用库和框架的兼容性，兼容性良好。只要能在il2cpp backend下工作的库都可以在huatuo下正常工作。甚至那些与il2cpp因为AOT问题不兼容的库，现在因为huatuo对il2cpp的能力扩充，反而可以正常运行了。具体参见 [兼容性报告](https://focus-creative-games.github.io/huatuo/performance/compatible/)
- 已经有几十个大中型游戏项目较完整地接入huatuo，并且其中一些在紧锣密鼓作上线前测试。具体参见收集的一些 [完整接入的商业项目列表](https://focus-creative-games.github.io/huatuo/ref_project/)

## 支持与联系

- 开发交流，欢迎加QQ群或邮件联系
  - QQ群：651188171 huatuo技术交流群 **(官方主群)**。可以反馈bug，但**不要在群里咨询基础使用问题**。
  - QQ群：428404198 huatuo使用疑难咨询群 **(新手群)**。新手使用过程中遇到问题，都可以在群里咨询。
  - 邮箱：taojingjian#gmail.com

- 商务合作，请联系Lucas Zhang
  - 电话：15201249045
  - 微信：lucaszhang1993
  - 邮箱：zhangshuo@tuyoogame.com

## RoadMap

huatuo虽然与il2cpp相关，但绝大多数核心代码独立于il2cpp，很容易移植（预计一个月）到其他不支持AOT+Interpreter的CLR平台。无论unity如何版本变迁，哪怕废弃了il2cpp改用.net 6+，huatuo会持续跟进，稳定地提供跨平台的CLR热更新服务，直至某天.net官方直接支持AOT+Interpreter，则huatuo完成其历史使命。

- 支持Unity 2019、2020和2021系列版本 (2022.6 -)
- 支持32位 (2022.6 - 2022.7)
- 指令优化，编译后指令数减少到原来1/4-1/2，基础指令和大多数对象模型指令有100%-300%的性能提升。 (2022.7 -)
- 支持增量式gc (2022.8 -)

## license

Huatuo is licensed under the [MIT](https://github.com/focus-creative-games/huatuo/blob/main/LICENSE) license
