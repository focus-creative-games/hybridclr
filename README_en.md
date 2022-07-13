#HybridCLR

[![license](http://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/focus-creative-games/hybridclr/blob/main/LICENSE)

HybridCLR is a **near-perfect** Unity full-platform native c# hot update solution with complete features, zero cost, high performance, and low memory.

HybridCLR expands the code of il2cpp, making it change from a pure [AOT](https://en.wikipedia.org/wiki/Ahead-of-time_compilation) runtime to a 'AOT+Interpreter' hybrid runtime, which supports dynamic loading of assemblies natively , so that games packaged based on il2cpp backend can be efficiently executed in **AOT+interpreter** mixed mode not only on Android platform, but also on IOS, Consoles and other platforms that restrict JIT. Hot updates are fully supported from the bottom up.

HybridCLR **pioneering implementation of the `differential hybrid dll` technology** ====. That is, the AOT dll can be arbitrarily added, deleted or modified, and HybridCLR will intelligently make the changed or newly added classes and functions run in the interpreter mode, but the unmodified classes and functions run in the AOT mode, so that the running performance of the hot-updated game logic can be basically achieved. The level of native AOT.

## Features

- Features complete. Nearly complete implementation of the [ECMA-335 specification](https://www.ecma-international.org/publications-and-standards/standards/ecma-335/), except for the features below "Limitations and Notes" are supported.
- Zero learning and usage costs. HybridCLR enhances the pure AOT runtime into a full runtime, making hot update code work seamlessly with AOT code. Script classes and AOT classes can write code such as inheritance, reflection, multi-threading (volatile, ThreadStatic, Task, async) at will in the same runtime. There is no need to write any special code, no code generation, and no special restrictions.
- Execute efficiently. Implemented an extremely efficient register interpreter that outperformed other hot update schemes by a large margin by all metrics. [Performance test report](https://focus-creative-games.github.io/hybridclr/benchmark/#performance test report)
- Memory efficient. The classes defined in the hot update script occupy the same memory space as ordinary C# classes, which is far superior to other hot update solutions. [Memory usage report](https://focus-creative-games.github.io/hybridclr/benchmark/#Memory usage report)
- Native support for hotfix to repair part of AOT code. Adds almost no development and runtime overhead.
- **Pioneering implementation of `differential hybrid dll` technology**. That is, a hot update dll can be packaged in AOT form first, and then the dll can be added, deleted or modified arbitrarily. HybridCLR will intelligently make the changed or added classes and functions run in interpreter mode, but the unmodified classes and functions run in AOT mode. run. This means that the running performance of the hot-updated game logic will be close to the level of native AOT.

## working principle

HybridCLR is inspired by mono's [hybrid mode execution](https://developpaper.com/new-net-interpreter-mono-has-arrived/) technology and provides additional interpreter modules for AOT runtimes such as unity's il2cpp , transform them from pure AOT runtime to "AOT + Interpreter" hybrid runtime.

![icon](docs/images/architecture.png)

More specifically, HybridCLR does the following:

- Implemented an efficient metadata (dll) parsing library
- Modified the metadata management module to realize the dynamic registration of metadata
- Implemented a compiler from an IL instruction set to a custom register instruction set
- Implemented an efficient register interpreter
- Provide a large number of instinct functions additionally to improve the performance of the interpreter
- Provide hotfix AOT support

## Differences from other popular c# hot update schemes

### Essential comparison

HybridCLR is a native c# hot update solution. In layman's terms, il2cpp is equivalent to the aot module of mono, and HybridCLR is equivalent to the interpreter module of mono. The two are combined into a complete mono. HybridCLR makes il2cpp a full-featured runtime that natively (ie, through System.Reflection.Assembly.Load) supports dynamic loading of dlls, thereby supporting hot updates of the ios platform.

Because HybridCLR is implemented at the native runtime level, the type of the hot update part is completely equivalent and seamlessly unified with the type of the AOT part of the main project. You can call, inherit, reflect, and multithread at will, without generating code or writing adapters.

Other hot update schemes are independent vms, and the relationship with il2cpp is essentially equivalent to the relationship of embedding lua in mono. Therefore, the type system is not unified. In order to allow the hot update type to inherit some types of AOT, an adapter needs to be written, and the type in the interpreter cannot be recognized by the type system of the main project. Incomplete features, troublesome development, and inefficient operation.

### Actual use experience or feature comparison

- HybridCLR costs almost zero to learn and use. HybridCLR turns il2cpp into a full-featured runtime with almost zero learning and usage costs and almost zero intrusion. Other schemes have a lot of pits and rules that need to be avoided, learning and use costs, and need to make a lot of modifications to the original project.
- HybridCLR can use all c# features. Other schemes tend to have a lot of restrictions.
- HybridCLR can directly support the use and inheritance of types in the main project. Other solutions are to write adapters or generate code.
- The hot update part of the metadata in HybridCLR is seamlessly unified with the AOT metadata. Like the reflection code can work properly, the AOT part can also create hot update objects through the standard Reflection interface. Other options can't do it.
- HybridCLR has good multithreading support. Features like multithreading, ThreadStatic, async, etc. are directly supported by HybridCLR, and other solutions are difficult to support except for the async feature.
- The Unity workflow in HybridCLR is almost identical to the native one. The hot update MonoBehaviour in HybridCLR can be directly mounted on the hot update resource and work correctly. Other options do not work.
- HybridCLR compatibility is extremely high. Various third-party libraries can work under HybridCLR as long as they work under il2cpp. Other solutions often require a lot of magic to modify the source code.
- HybridCLR is extremely memory efficient. The hot update type in HybridCLR is completely equivalent to the AOT type of the main project, occupying the same amount of space. The equivalent types of other schemes are false types, which not only cannot be recognized by the runtime, but also occupy several times more space.
- HybridCLR performs efficiently. The interaction between the hot update part in HybridCLR and the AOT part of the main project belongs to the internal interaction of il2cpp, which is extremely efficient. The other solution is the efficiency between the independent virtual machine and il2cpp, which is not only troublesome but also inefficient.

## Documentation

- [documentation site](https://focus-creative-games.github.io/), **recommended**
- [FAQ](https://focus-creative-games.github.io/hybridclr/faq/)
- [limitations and caveats](https://focus-creative-games.github.io/hybridclr/performance/limit/)
- [Sample Project](https://github.com/focus-creative-games/hybridclr_trial)
- [Know the column] (https://www.zhihu.com/column/c_1489549396035870720)
- [==>Acknowledgments<==](https://focus-creative-games.github.io/hybridclr/donate/)

## Stability status

=== **Celebrated the official launch of the first android and iOS dual-end casual game using HybridCLR in 2021.6.7** ===, there will be several medium-heavy games online or external testing in July.

In terms of technical evaluation, the stability is currently in the Beta version. Due to the advanced nature of HybridCLR technical principles, there are not many bugs in nature, and the stability is very fast.

- At present, PC, Android, and iOS have run through all unit tests and can be used stably.
- Tested the compatibility of common game libraries and frameworks, and the compatibility is good. Any library that works under the il2cpp backend will work fine under HybridCLR. Even those libraries that are incompatible with il2cpp due to AOT issues can now run normally because of HybridCLR's expanded capabilities for il2cpp.
- Dozens of large and medium-sized game projects have been integrated into HybridCLR, and some of them are being tested before going live. For details, please refer to some collected [complete access to commercial projects list](https://focus-creative-games.github.io/hybridclr/ref_project/)

## Support and Contact

- For development communication, welcome to join QQ group or email contact
  - QQ group: 651188171 HybridCLR technical exchange group **(official main group)**. You can report bugs, but **do not consult basic usage issues in the group**.
  - QQ group: 428404198 HybridCLR use problem consultation group **(novice group)**. If you encounter any problems in the process of using it, you can consult in the group.
  - Email: taojingjian#gmail.com

## RoadMap

Although HybridCLR is related to il2cpp, most of the core code is independent of il2cpp, and it is easy to transplant (expected one month) to other CLR platforms that do not support AOT+Interpreter. No matter how the version of Unity changes, even if il2cpp is abandoned and .net 6+ is used, HybridCLR will continue to follow up and stably provide cross-platform CLR hot update service until one day when .net officially supports AOT+Interpreter, then HybridCLR will complete its historical mission.

- Support for Unity 2019, 2020 and 2021 series versions (2022.6 -)
- Instruction optimization, the number of instructions after compilation is reduced to 1/4-1/2, and the performance of basic instructions and most object model instructions is improved by 100%-300%. (2022.7-)
- Support incremental gc (2022.8 -)

## license

HybridCLR is licensed under the [MIT](https://github.com/focus-creative-games/hybridclr/blob/main/LICENSE) license