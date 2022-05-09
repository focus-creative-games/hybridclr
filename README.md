
# huatuo

[![license](http://img.shields.io/badge/license-MIT-blue.svg)](https://opensource.org/licenses/MIT)

<br/>

![icon](docs/images/logo.png)

<br/>

huatuo是一个**特性完整、零成本、高性能、低内存**的**近乎完美**的Unity全平台原生c#热更方案。

huatuo扩充了il2cpp的代码，使它由纯[AOT](https://en.wikipedia.org/wiki/Ahead-of-time_compilation) runtime变成‘AOT+Interpreter’ 混合runtime，进而原生支持动态加载assembly，使得基于il2cpp backend打包的游戏不仅能在Android平台，也能在IOS、Consoles等限制了JIT的平台上高效地以**AOT+interpreter**混合模式执行。从底层彻底支持了热更新。

## 特性

- 特性完整。 近乎完整实现了[ECMA-335规范](https://www.ecma-international.org/publications-and-standards/standards/ecma-335/)，除了 下文中"限制和注意事项" 之外的特性都支持。
- 零学习和使用成本。 huatuo将纯AOT runtime增强为完整的runtime，使得热更新代码与AOT代码无缝工作。脚本类与AOT类在同一个运行时内，可以随意写继承、反射、多线程(volatile、ThreadStatic、Task、async)之类的代码。不需要额外写任何特殊代码、没有代码生成，也没有什么特殊限制。
- 执行高效。实现了一个极其高效的寄存器解释器，所有指标都大幅优于其他热更新方案。[性能测试报告](https://github.com/focus-creative-games/huatuo/wiki/benchmark)
- 内存高效。 热更新脚本中定义的类跟普通c#类占用一样的内存空间，远优于其他热更新方案。[内存占用报告](https://github.com/focus-creative-games/huatuo/wiki/memory)
- 原生支持hotfix修复AOT部分代码。几乎不增加任何开发和运行开销。

## 工作原理

huatuo从mono的[Hybrid mode execution](https://developpaper.com/new-net-interpreter-mono-has-arrived/)技术中得到启发，为unity的il2cpp之类的AOT runtime额外提供了interpreter模块，将它们由纯AOT运行时改造为"AOT + Interpreter"混合运行方式。

![icon](docs/images/architecture.png)

更具体地说，huatuo做了以下几点工作：

- 实现了一个高效的元数据(dll)解析库
- 改造了元数据管理模块，实现了元数据的动态注册
- 实现了一个IL指令集到自定义的寄存器指令集的compiler
- 实现了一个高效的寄存器解释器
- 额外提供大量的instinct函数，提升解释器性能
- 提供hotfix AOT的支持 （进行中）

## 与其他流行的c#热更新方案的区别

简单类比，将il2cpp比作一只没有翅膀的鸟儿，只能地面行走，huatuo则让il2cpp直接长出原生翅膀，可以飞翔。 而其他热更方案则类似于做了一个飞行器，让它可以乘坐飞起来。

### 本质比较

huatuo是原生的c#热更新方案。通俗地说，il2cpp相当于mono的aot模块，huatuo相当于mono的interpreter模块，两者合一成为完整mono。huatuo使得il2cpp变成一个全功能的runtime，原生（即通过System.Reflection.Assembly.Load）支持动态加载dll，从而支持ios平台的热更新。

正因为huatuo是原生runtime级别实现，热更新部分的类型与主工程AOT部分类型是完全等价并且无缝统一的。可以随意调用、继承、反射、多线程，不需要生成代码或者写适配器。

其他热更新方案则是独立vm，与il2cpp的关系本质上相当于mono中嵌入lua的关系。因此类型系统不统一，为了让热更新类型能够继承AOT部分类型，需要写适配器，并且解释器中的类型不能为主工程的类型系统所识别。特性不完整、开发麻烦、运行效率低下。

### 实际使用体验或者特性比较

- huatuo学习和使用成本几乎为零。huatuo 让il2cpp变成全功能的mono，学习和使用成本几乎为零，几乎零侵入性。而其他方案则有大量的坑和需要规避的规则，学习和使用成本，需要对原项目作大量改造。
- huatuo可以使用所有c#的特性。而其他方案往往有大量的限制。
- huatuo中可以直接支持使用和继承主工程中的类型。其他方案要写适配器或者生成代码。
- huatuo中热更新类型与主工程的AOT类型无缝统一。huatuo中反射代码能够正常工作的，主工程部分也可以通过标准Reflection接口创建出热更新对象。其他方案做不到。
- huatuo对多线程支持良好。像多线程、ThreadStatic、async等等特性都是huatuo直接支持，其他方案除了async特性外均难以支持。
- huatuo中Unity工作流与原生几乎完全相同。huatuo中热更新MonoBehaviour可以直接挂载在热更新资源上，并且正确工作。其他方案不行。
- huatuo兼容性极高。各种第三方库只要在il2cpp下能工作，在huatuo下也能正常工作。其他方案往往要大量魔改源码。
- huatuo内存效率极高。huatuo中热更新类型与主工程的AOT类型完全等价，占用一样多的空间。其他方案的同等类型则是假类型，不仅不能被runtime识别，还多占了数倍空间。
- huatuo执行效率高。huatuo中热更新部分与主工程AOT部分交互属于il2cpp内部交互，效率极高。而其他方案则是独立虚拟机与il2cpp之间的效率，不仅交互麻烦还效率低下。

## 文档

- [wiki](https://github.com/focus-creative-games/huatuo/wiki/home)
- [快速上手](https://github.com/focus-creative-games/huatuo/wiki/start_up)
- [FAQ](https://github.com/focus-creative-games/huatuo/wiki/FAQ)
- [限制和注意事项](https://github.com/focus-creative-games/huatuo/wiki/limit)
- [常见错误](https://github.com/focus-creative-games/huatuo/wiki/common_errors)
- [最佳实践](https://github.com/focus-creative-games/huatuo/wiki/best_practices)
- [源码结构与跟踪调试](https://github.com/focus-creative-games/huatuo/wiki/source_inspect)
- [示例项目](https://github.com/focus-creative-games/huatuo_trial)
- [知乎专栏](https://www.zhihu.com/column/c_1489549396035870720)
- [==>致谢名单<==](https://github.com/focus-creative-games/huatuo/wiki/donate)

## 稳定性状况

技术评估上目前稳定性处于Alpha版本与Beta版本之间。由于huatuo技术原理的先进性，bug本质不多，稳定得非常快。

- 完成了绝大多数指令的单元测试。只有calli、initblk等少数难以直接在c#里构造的指令未添加对应的单元测试。
- 对照c#规范完成各项语法测试。
- 测试了游戏常用库和框架的兼容性，兼容性良好。只要能在il2cpp backend下工作的库都可以在huatuo下正常工作。参见[兼容性报告](https://github.com/focus-creative-games/huatuo/wiki/compatible)
- 可以正确地加载 [luban](https://github.com/focus-creative-games/luban) 配置
- 可以正确地运行 [2048](https://github.com/dgkanatsios/2048)这样的轻量小游戏
- 可以运行 [StarForce](https://github.com/EllanJiang/StarForce) 这样的小型游戏
- **==已经可以在pc平台完整运行重度MMORPG项目==**。目前正在积极推进android、ios、WebGL平台的测试工作。预计5月底会有较稳定的全平台版本。

预计在7月份会有使用huatuo的重度MMORPG项目上线。

## 支持与联系

* 开发交流，欢迎加QQ群或邮件联系walon
  * QQ群: 651188171（huatuo c#热更新 开发交流群）
  * 邮箱: taojingjian#gmail.com

* 商务合作，请联系Lucas Zhang
  * 电话：15201249045
  * 微信：lucaszhang1993
  * 邮箱：zhangshuo@tuyoogame.com

## RoadMap

huatuo虽然与il2cpp相关，但绝大多数核心代码独立于il2cpp，很容易移植（预计一个月）到其他不支持AOT+Interpreter的CLR平台。无论unity如何版本变迁，哪怕废弃了il2cpp改用.net 6+，huatuo会持续跟进，稳定地提供跨平台的CLR热更新服务，直至某天.net官方直接支持AOT+Interpreter，则huatuo完成其历史使命。

- 持续修复bug，在Win平台能正常运行一个中大型游戏 (2022.4)
- 持续跟进unity的版本更新，支持更多的unity版本。查看[现在支持的Unity版本](https://github.com/focus-creative-games/huatuo/wiki/support_versions) (2022.4)
- 推进Android与ios的全平台测试 (2022.5)
- 支持 hotfix AOT部分的bug (2022.6)
- 除去大多数普通AOT泛型类限制 (2022.6)
- 支持增量式gc。 (2022.7)
- 指令优化，编译后指令数减少到原来1/4-1/2，基础指令和大多数对象模型指令有100%-300%的性能提升。 (2022.7 出预览版本)
- 支持 extern函数 (2022.7)
- 其他内存和效率优化，以及代码重构
- **===支持godot引擎===**(2022.12)

## license

Huatuo is licensed under the [MIT](https://github.com/focus-creative-games/luban/blob/main/LICENSE.TXT) license
