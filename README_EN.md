- [README Chinese](./README.md)
- [README English](./README_EN.md)

# HybridCLR

[![license](http://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/focus-creative-games/hybridclr/blob/main/LICENSE)

![logo](./docs/images/logo.jpg)

<br/>
<br/>

HybridCLR is a **feature-complete, zero-cost, high-performance, low-memory** and **nearly perfect** native C# hot update solution for Unity across all platforms.

HybridCLR extends the il2cpp runtime, transforming it from a pure [AOT](https://en.wikipedia.org/wiki/Ahead-of-time_compilation) runtime into a hybrid AOT+Interpreter runtime, natively supporting dynamic assembly loading and fundamentally enabling hot updates. Games using HybridCLR technology can run efficiently not only on Android but also on iOS, consoles, WebGL, and all platforms supported by il2cpp.

Thanks to HybridCLR's strong support for the ECMA-335 specification and high compatibility with Unity's development workflow, Unity projects can seamlessly gain C# hot update capabilities after integration, without developers needing to change their daily habits or requirements. HybridCLR is the first to reduce the engineering difficulty of full-platform code hot updates for Unity to nearly zero.

Embrace modern native C# hot update technology!

## Documentation

- [Official Documentation](https://www.hybridclr.cn/docs/intro)
- [Quick Start](https://www.hybridclr.cn/docs/beginner/quickstart)
- [Commercial Project Cases](https://www.hybridclr.cn/docs/other/businesscase)
- [LeanCLR](https://github.com/focus-creative-games/leanclr)

## Features

- Nearly complete implementation of the [ECMA-335 specification](https://www.ecma-international.org/publications-and-standards/standards/ecma-335/), with only a few [unsupported features](https://www.hybridclr.cn/docs/basic/notsupportedfeatures).
- Zero learning and usage cost. For most developers, there are almost no coding restrictions. Hot update code and AOT code work seamlessly; you can freely use inheritance, **generics**, **reflection**, etc. No need for special code or code generation.
- Full multi-threading support, including but not limited to volatile, ThreadStatic, async Task, and related features. This is not supported by any other hot update solution.

- Almost fully compatible with Unity's workflow, including support for hot update **MonoBehaviour**, ScriptableObject, **DOTS** technology, and correct instantiation of hot update scripts attached to resources. This is not supported by any other hot update solution.
- Efficient execution. Features an extremely efficient register interpreter, outperforming other hot update solutions in all metrics. [Performance Test Report](https://www.hybridclr.cn/docs/basic/performance)
- Memory efficient. Classes defined in hot update scripts occupy the same memory as regular C# classes, far superior to other hot update solutions. [Memory Usage Report](https://www.hybridclr.cn/docs/basic/memory)

- Supports MonoPInvokeCallback for good interaction with native code or other languages like lua, javascript, python.
- Supports some features not supported by il2cpp, such as __makeref, __reftype, __refvalue instructions.
- Supports the original **Differential Hybrid Execution (DHE)** technology, allowing arbitrary addition, deletion, and modification of AOT dlls. Unchanged functions run in AOT mode, changed or new functions run in interpreter mode, making hot update game logic performance nearly native AOT level.

- Supports **hot reload** technology, allowing 100% assembly unloading.
- Supports **hotfix** technology, enabling bug fixes without restarting the game.
- Supports modern dll encryption technology for effective code security.

## Supported Versions and Platforms

- Supports all LTS versions: 2019.4.x, 2020.3.x, 2021.3.x, 2022.3.x, 2023.2.x, 6000.x.y
- Supports all platforms supported by il2cpp
- Supports Unity Engine and HarmonyOS platforms

## How It Works

HybridCLR is inspired by mono's [mixed mode execution](https://www.mono-project.com/news/2017/11/13/mono-interpreter/) technology, providing an interpreter module for Unity's il2cpp and similar AOT runtimes, transforming them from pure AOT runtimes to "AOT + Interpreter" hybrid execution.

## Stability

HybridCLR has been widely validated as a highly efficient and stable Unity hot update solution, meeting the stability and performance requirements of medium and large commercial projects.

Thousands of commercial game projects have integrated HybridCLR, with over a thousand already launched on the App Store and Google Play. Nearly a hundred games in the top 500 free iOS chart use HybridCLR. Released projects include MMORPGs, heavy card games, tower defense, and more. Most top game companies in China are already using HybridCLR.

See our known list of top companies using HybridCLR and already launched [project list](https://www.hybridclr.cn/docs/other/businesscase).

## Support & Contact

- Official Group 1 (3000 members): 651188171 (full)
- Newbie Group 1 (3000 members): 428404198 (full)
- Newbie Group 2 (2000 members): 680274677 (full)
- Newbie Group 3 (2000 members): **920714552 (recommended)**
- Discord channel: <https://discord.gg/BATfNfJnm2>
- Business cooperation email: business#code-philosophy.com
- [Commercial Support](https://www.hybridclr.cn/docs/business/intro)

## LeanCLR Project

HybridCLR is just an interpreter module. If you need a complete, compact, open-source CLR implementation suitable for mobile and mini-game platforms, [LeanCLR](https://github.com/focus-creative-games/leanclr) is currently the best solution.

LeanCLR can be embedded independently into any app or game project and published to any platform. It can also **replace il2cpp as the runtime for Unity (Unity Engine) when publishing to webgl and mini-game platforms**, greatly reducing package size and memory usage.

## About the Author

**walon**: Founder of **Code Philosophy**

Graduated from Tsinghua University, Department of Physics. 2006 CMO gold medalist, member of the national math olympiad training team, admitted to Tsinghua's basic science class. Focused on game technology, skilled in development architecture and core technical infrastructure.

## License

HybridCLR is licensed under the [MIT](https://github.com/focus-creative-games/hybridclr/blob/main/LICENSE) license

- [README Chinese](./README.md)
- [README English](./README_EN.md)