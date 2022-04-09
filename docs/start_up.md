# huatuo

参考资料

- [示例项目](https://github.com/focus-creative-games/huatuo_trial)
- [huatuo尝鲜视频教程](https://www.bilibili.com/video/BV1QL411w7z2/)

## 使用

以下为了方便起见，发布win下pc版本。其他平台同理。

### 安装

- 为你所用的Unity版本安装适当的il2cpp模块，（如果你发布其他平台，要选择相应平台的il2cpp模块）。
- 从[il2cpp_huatuo](https://github.com/pirunxi/il2cpp_huatuo) clone你所用的unity版本对应的分支
- 将huatuo目录复制到 il2cpp_huatuo/libil2cpp下，最终目录为il2cpp_huatuo/libil2cpp/huatuo。
- 用il2cpp_huatuo项目的libil2cpp目录替换你当前所用的Unity的Editor安装目录下的 Editor/Data/il2cpp/libil2cpp 目录。

**至此即完成huatuo安装，后续打包出的app就能支持c#热更新。**

### 项目的准备工作

- 使用 Unity的 Assembly def 创建一个专门的 HotFix 模块（你也可以使用创建第三方工程的方式，只不过麻烦了点）。
- 配置HotFix模块
  - 根据需求设置正确的Assembly Definition Reference。
  - Platforms 选项下，取消AnyPlatform，接着只选中 Editor和随便一个**不导出**的平台（如XboxOne）。不能只有Editor，因为Unity会把它当作纯Editor模板，不允许加载MonoBehaviour。
- 将示例项目Assets/Main/HuatuoLib 以及Assets/link.xml 拷贝到 你项目中。link.xml文件可酌情调整。

### 代码中使用

- 在HotFix模块中创建第一个热更新脚本，类似如下

```c#
public class App
{
    public static int Main()
    {
        Debug.Log("hello,huatuo");
        return 0;
    }
}
```

- 主工程中，使用标准反射函数加载Hotfix.dll,以示例 LoadDll.cs 为例

- 如果需要加载AssetBundle, 请查看示例工程中的LoadDllFromAssetbundle.cs文件

  同时也在菜单中添加了简单hotfix.dll文件的ab制作工具

```c#

public class LoadDll : MonoBehaviour
{
    void Start()
    {
        LoadGameDll();
        RunMain();
    }

    private System.Reflection.Assembly gameAss;

    private void LoadGameDll()
    {
#if UNITY_EDITOR
        string gameDll = Application.dataPath + "/../Library/ScriptAssemblies/HotFix.dll";
        // 使用File.ReadAllBytes是为了避免Editor下gameDll文件被占用导致后续编译后无法覆盖
        gameAss = System.Reflection.Assembly.Load(File.ReadAllBytes(gameDll));
#else
        // 此代码在Android等平台下并不能工作，请酌情调整
        string gameDll = Application.streamingAssetsPath + "/HotFix.dll";
        gameAss = System.Reflection.Assembly.LoadFile(File.ReadAllBytes(gameDll));
#endif
    }

    public void RunMain()
    {
        if (gameAss == null)
        {
            UnityEngine.Debug.LogError("dll未加载");
            return;
        }
        var appType = gameAss.GetType("App");
        var mainMethod = appType.GetMethod("Main");
        mainMethod.Invoke(null, null);
    }
}
```

- Build & Run
  - 将 HotFix.dll拷到StreamingAssets下
  - 发布选项设置
    - Scripting Backend 选择 il2cpp backend
    - 取消 use incremental GC
  - 发布 (必须选择相应平台64位版本)
  - 进入场景后，应该能看到日志 "hello,huatuo"

- 测试热更新

修改HotFix模块中的 App::Main代码。改成

```c#
public class App
{
    public static int Main()
    {
        Debug.Log("hello,world");
        return 0;
    }
}
```

将编译后的Hotfix.dll 复制替换发布目标目录下的 StreamingAssets下的Hotfix.dll，重新运行程序。
你应该会看到打印出 "hello,world"。

至此完成。
