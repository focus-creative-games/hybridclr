
- [README Chinese](./README.md)
- [README English](./README_EN.md)

# HybridCLR

[![license](http://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/focus-creative-games/hybridclr/blob/main/LICENSE)

![logo](./docs/images/logo.jpg)

<br/>
<br/>

HybridCLR is a **feature-complete, zero-cost, high-performance, low-memory** **near-perfect** Unity cross-platform native C# hot update solution.

HybridCLR extends the il2cpp runtime code, transforming it from a pure [AOT](https://en.wikipedia.org/wiki/Ahead-of-time_compilation) runtime to an AOT+Interpreter hybrid runtime, thereby natively supporting the dynamic loading of assemblies and fundamentally supporting hot updates from the bottom layer. Games using HybridCLR technology can not only run efficiently on the Android platform but also on all platforms supported by il2cpp, including iOS, Consoles, WebGL, etc.

Thanks to HybridCLR's good support for the ECMA-335 specification and its high compatibility with the Unity development workflow, Unity projects can almost seamlessly gain the ability to hot update C# code after integrating HybridCLR. Developers do not need to change their daily development habits and requirements. HybridCLR is the first to achieve the engineering difficulty of a full-platform code hot update solution for the Unity platform to almost zero.

Welcome to embrace modern native C# hot update technology!

## Documentation

- [Official Documentation](https://hybridclr.doc.code-philosophy.com/en/docs/intro)
- [Quick Start](https://hybridclr.doc.code-philosophy.com/en/docs/beginner/quickstart)
- [Business Project Cases](https://hybridclr.doc.code-philosophy.com/en/docs/other/businesscase)

## Features

- Nearly complete implementation of the [ECMA-335 specification](https://www.ecma-international.org/publications-and-standards/standards/ecma-335/), with only a very small number of [unsupported features](https://hybridclr.doc.code-philosophy.com/en/docs/basic/notsupportedfeatures).
- Zero learning and usage costs. For most developers, writing code is almost unrestricted. Hot update code works seamlessly with AOT code, allowing for inheritance, **generics**, **reflection**, and other code without additional special code or code generation.
- Full support for multithreading, including but not limited to volatile, ThreadStatic, async Task, and related features and characteristics. This is not supported by any other hot update solution.
- Almost complete compatibility with Unity's workflow. This includes support for hot updating **MonoBehaviour**, ScriptableObject, **DOTS** technology, and correctly instantiating hot update scripts mounted on resources, which is not supported by any other hot update solution.
- Efficient execution. A highly efficient register interpreter has been implemented, with all indicators significantly better than other hot update solutions. [Performance Test Report](https://hybridclr.doc.code-philosophy.com/en/docs/basic/performance)
- Efficient memory usage. Classes defined in hot update scripts occupy the same memory space as ordinary C# classes, far superior to other hot update solutions. [Memory Usage Report](https://hybridclr.doc.code-philosophy.com/en/docs/basic/memory)
- Supports MonoPInvokeCallback, enabling good interaction with native code or other languages such as Lua, JavaScript, Python.
- Supports some features not supported by il2cpp, such as __makeref, __reftype, __refvalue instructions.
- Supports the unique **Differential Hybrid Execution (DHE)** technology, which allows for arbitrary additions, deletions, and modifications to AOT DLLs. It intelligently runs unchanged functions in AOT mode and changed or newly added functions in interpreter mode, bringing the performance of hot-updated game logic close to that of native AOT.
- Supports **hot reload** technology, allowing 100% unloading of assemblies.
- Supports **Hotfix** technology, allowing for bug fixes without the need to restart the game, resulting in a seamless repair experience.
- Supports modern DLL encryption technology to effectively protect code security.

## Supported Versions and Platforms

- Supports all LTS versions including 2019.4.x, 2020.3.x, 2021.3.x, 2022.3.x, 2023.2.x, 6000.0.x.
- Supports all platforms supported by il2cpp.
- Supports Tuanjie(China) Engine and HarmonyOS platform.

## Working Principle

HybridCLR draws inspiration from Mono's [mixed mode execution](https://www.mono-project.com/news/2017/11/13/mono-interpreter/) technology, providing an interpreter module for AOT runtimes like Unity's il2cpp, transforming them from pure AOT runtimes to "AOT + Interpreter" hybrid operation modes.

![icon](docs/images/architecture.png)

More specifically, HybridCLR has done the following:

- Implemented an efficient metadata (dll) parsing library.
- Modified the metadata management module to achieve dynamic registration of metadata.
- Implemented a compiler that converts IL instructions to a custom register instruction set.
- Implemented an efficient register interpreter.
- Provided a large number of instinct functions to enhance interpreter performance.

## Stability Status

HybridCLR has been widely verified as an efficient and stable Unity hot update solution, meeting the stability and performance requirements of medium and large commercial projects.

Currently, thousands of commercial game projects have integrated HybridCLR, with over a thousand already launched on the App Store and Google Play. Nearly a hundred of the top 500 free iOS games use HybridCLR, including MMORPGs, heavy card games, and heavy tower defense games. Most of the **Top Game Companies** in China are already using HybridCLR.

You can view the [list of known top companies using HybridCLR and their launched projects](https://hybridclr.doc.code-philosophy.com/en/docs/other/businesscase).

## Support and Contact

- Official Group 1: 651188171 (Full)
- Beginner Group 1: 428404198 (Full)
- Beginner Group 2: **680274677 (Recommended)**
- Discord channel https://discord.gg/BATfNfJnm2
- Business cooperation email: business#code-philosophy.com
- [Commercial Support](https://hybridclr.doc.code-philosophy.com/en/docs/business/intro)

## About the Author

**walon**: Founder of **Code Philosophy (代码哲学)**

Graduated from the Department of Physics at Tsinghua University, gold medalist of the 2006 CMO, member of the National Mathematical Olympiad Training Team, and sent to the Basic Science Class of Tsinghua. Focused on game technology, proficient in development architecture and basic technical infrastructure.

## License

HybridCLR is licensed under the [MIT](https://github.com/focus-creative-games/hybridclr/blob/main/LICENSE) license.
