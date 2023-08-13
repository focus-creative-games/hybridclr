
- [README 中文](./README_zh.md)
- [README English](./README.md)

# HybridCLR

[![license](http://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/focus-creative-games/hybridclr/blob/main/LICENSE)

![logo](./docs/images/logo.jpg)

<br/>
<br/>

HybridCLR is the excellent work of **Code Philosophy** company. We hope to profoundly change the entire industry through our ingenuity and help game teams make better games.

HybridCLR is a **almost perfect** full-platform native c# hot update solution for Unity with complete features, zero cost, high performance, and low memory**.

HybridCLR expands the ability of il2cpp, making it change from pure [AOT](https://en.wikipedia.org/wiki/Ahead-of-time_compilation) runtime to 'AOT+Interpreter' hybrid runtime, and then natively supports dynamic loading of assembly , so that the games packaged based on il2cpp backend can be executed not only on the Android platform, but also on IOS, Consoles and other platforms that limit JIT efficiently in **AOT+interpreter** hybrid mode, completely supporting hot updates from the bottom layer.

HybridCLR not only supports the traditional fully interpreted execution mode, but also pioneered [Differential Hybrid Execution](https://hybridclr.doc.code-philosophy.com/en/docs/basic/differentialhybridexecution) technique. That is, you can add, delete, or modify the AOT dll at will, and intelligently make the changed or newly added classes and functions run in interpreter mode, but the unchanged classes and functions run in AOT mode, so that the running performance of the hot-updated game logic basically reaches the original AOT level.

Welcome to embrace modern native C# hot update technology! ! !

## Documentation

- [Official Documentation](https://hybridclr.doc.code-philosophy.com/en/en/docs/intro)
- [Quick Start](https://hybridclr.doc.code-philosophy.com/en/en/docs/beginner/quickstart)

## Features

- Features complete. A nearly complete implementation of the [ECMA-335 specification](https://www.ecma-international.org/publications-and-standards/standards/ecma-335/), with only a very small number of [unsupported features](https://hybridclr.doc.code-philosophy.com/en/docs/basic/notsupportedfeatures).
- Zero learning and use costs. HybridCLR enhances the pure AOT runtime into a complete runtime, making hot update code work seamlessly with AOT code. The script class and the AOT class are in the same runtime, and you can freely write codes such as inheritance, reflection, and multi-threading (volatile, ThreadStatic, Task, async). No need to write any special code, no code generation, almost unlimited.
- Efficient execution. Implemented an extremely efficient register interpreter, all indicators are significantly better than other hot update schemes. [Performance Test Report](https://hybridclr.doc.code-philosophy.com/en/docs/basic/performance)
- Memory efficient. The classes defined in the hot update script occupy the same memory space as ordinary c# classes, which is far superior to other hot update solutions. [Memory and GC](https://hybridclr.doc.code-philosophy.com/en/docs/basic/memory)
- Due to the perfect support for generics, libraries that are not compatible with il2cpp due to AOT generics issues can now run perfectly under il2cpp
- Support some features not supported by il2cpp, such as __makeref, __reftype, __refvalue directives
- [Differential Hybrid Execution](https://hybridclr.doc.code-philosophy.com/en/docs/basic/differentialhybridexecution)

## working principle

HybridCLR is inspired by mono's [mixed mode execution](https://www.mono-project.com/news/2017/11/13/mono-interpreter/) technology, and provides additional AOT runtimes such as unity's il2cpp The interpreter module is provided to transform them from pure AOT runtime to "AOT + Interpreter" hybrid operation mode.

![icon](docs/images/architecture.png)

More specifically, HybridCLR does the following:

- Implemented an efficient metadata (dll) parsing library
- Modified the metadata management module to realize the dynamic registration of metadata
- Implemented a compiler from IL instruction set to custom register instruction set
- Implemented an efficient register interpreter
- Provide a large number of instinct functions to improve the performance of the interpreter

## The difference from other popular c# hot update schemes

HybridCLR is a native c# hot update solution. In layman's terms, il2cpp is equivalent to the aot module of mono, and HybridCLR is equivalent to the interpreter module of mono, and the combination of the two becomes a complete mono. HybridCLR makes il2cpp a full-featured runtime, natively (that is, through System.Reflection.Assembly.Load) supports dynamic loading of dlls, thereby supporting hot updates of the ios platform.

Just because HybridCLR is implemented at the native runtime level, the types of the hot update part and the AOT part of the main project are completely equivalent and seamlessly unified. You can call, inherit, reflect, and multi-thread at will, without generating code or writing adapters.

Other hot update solutions are independent vm, and the relationship with il2cpp is essentially equivalent to the relationship of embedding lua in mono. Therefore, the type system is not uniform. In order to allow the hot update type to inherit some AOT types, an adapter needs to be written, and the type in the interpreter cannot be recognized by the type system of the main project. Incomplete features, troublesome development, and low operating efficiency.

## Compatibility

- Support 2019.4.x, 2020.3.x, 2021.3.x, 2022.3.x, 2023.2.x series LTS versions
- Supports all platforms supported by il2cpp. At present, it has fully supported PC (Win32 and Win64), macOS (x86, x64, Arm64), Android (armv7, armv8), iOS (64bit), WebGL, **WeChat applet platform**, and the remaining platforms are yet to be tested.
- Tested a large number of common game libraries, and did not find a library that is natively compatible with il2cpp but incompatible after using HybridCLR. As long as the library can work under the il2cpp backend, it can work normally under HybridCLR. Even those libraries that are incompatible with il2cpp due to AOT issues can now run normally because of HybridCLR's ability to expand il2cpp.

## Stability Status

At present, **extremely stable** official versions 1.x, 2.x, and 3.x have been released, which are sufficient to meet the stability requirements of large and medium-sized commercial projects. Since the first game was launched on June 7, 2022, only one small bug occurred in the online project, and it was quickly fixed within a few hours.

At present, at least thousands of commercial game projects have completed access, and hundreds of them have been launched on both ends. The online projects include games such as MMORPG, heavy card, and heavy tower defense.

Most leading companies such as Tencent, NetEase, Baidu, funplus, Perfect, Stacked Paper, and Byte have already connected to multiple projects and will soon (or already) go online.

## Support and Contact

- Official 1 group: 651188171 (full)
- Novice group 1: 428404198 (full)
- Novice group 2: **680274677 (recommended)**
- QQ reward mutual aid group: 762953653. Offer a reward for asking questions and solving problems quickly.
- discord channel [https://discord.gg/BATfNfJnm2](https://discord.gg/BATfNfJnm2)
- Business cooperation email: business#code-philosophy.com
- [Commercial Support](https://hybridclr.doc.code-philosophy.com/en/docs/business/intro)

## About the author

**walon** : Founder of **Code Philosophy (code philosophy)**

Graduated from the Department of Physics of Tsinghua University, won the CMO gold medal in 2006, a member of the National Mathematical Olympiad Training Team, and was recommended to Tsinghua University for basic courses. Focus on game technology, good at developing architecture and basic technical facilities.

## license

HybridCLR is licensed under the [MIT](https://github.com/focus-creative-games/hybridclr/blob/main/LICENSE) license
