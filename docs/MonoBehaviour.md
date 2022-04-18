# 热更新MonoBehaviour的工作流

文档中提及的代码文件在[huatuo_trail](https://github.com/focus-creative-games/huatuo_trial)

## 通过代码使用

AddComponent&lt;T&gt;()或者AddComponent(Type type)都是完美支持的。

## 在资源上挂载MonoBehaviour

如果想在资源上挂载热更新脚本，由于unity资源管理的限制，需要在打包时做少量特殊处理。

### 准备工作

- 根据项目Unity版本不同，打开文件 `Assets/Editor/HuaTuo/HuaTuo_BuildProcessor_2020_1_OR_NEWER.cs` 或 `HuaTuo_BuildProcessor_2019.cs`，将需要在资源上挂脚本的所在热更dll名称填入 `monoDllNames` 字段，示例:

    ```csharp
        static List<string> monoDllNames = new List<string>() { "HotFix.dll"};
    ```

- 在挂热更脚本的任意一个资源加载之前，加载热更dll，示例代码如下:

    ```csharp
        #if !UNITY_EDITOR
            // 只有打包后才需要加载 HotFix.dll
            AssetBundle dllAB = BetterStreamingAssets.LoadAssetBundle("huatuo");
            TextAsset dllBytes = dllAB.LoadAsset<TextAsset>("HotFix.bytes");
            gameAss = System.Reflection.Assembly.Load(dllBytes.bytes);
        #endif

            // 加载热更dll之后再加载挂了热更脚本的资源
            AssetBundle resAB = BetterStreamingAssets.LoadAssetBundle("artRes");
            GameObject go = resAB.LoadAsset<GameObject>("myPrefab");
            Instantiate(go);
    ```

### 打包流程

正常打包即可，但有几个注意事项

- dll可以自由选择AssetBundle或者StreamingAssets或者其他方式更新。如需要把热更dll打包成ab，可参见示例 `Assets/Editor/HuaTuo/HuaTuoEditorHelper.cs`
- 建议打AB时不要禁用TypeTree，否则普通的AB加载方式会失败。（原因是对于禁用TypeTree的脚本，Unity为了防止二进制不匹配导致反序列化MonoBehaviour过程中进程Crash，会对脚本的签名进行校验，签名的内容是脚本FullName及TypeTree数据生成的Hash, 但由于我们的热更脚本信息不存在于打包后的安装包中，因此校验必定会失败）

- 如果必须要禁用TypeTree，一个变通的方法是禁止脚本的Hash校验, 此种情况下用户必须保证打包时代码与资源版本一致，否则可能会导致Crash，示例代码

    ```csharp
        AssetBundleCreateRequest req = AssetBundle.LoadFromFileAsync(path);
        req.SetEnableCompatibilityChecks(false); // 非public，需要通过反射调用
    ```

### 其它

- 不支持reload dll。想重新加载一个dll只能重启。
- **需要被挂到资源上的脚本所在dll名称（monoDllNames）请事先预留好，上线后勿修改，因为这个列表是无法热更的**
