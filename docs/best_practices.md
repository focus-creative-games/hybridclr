# 最佳实践

## unity版本推荐

推荐使用2020系列，最稳定。2019属于支持，但很快废弃的版本；2021版本Unity还有大量bug，我们正谨慎跟进。

## 原生与解释器部分性能敏感的场合不要用反射来交互，应该通过Delegate

以Update函数为例，大多数人会想到主工程跟热更部分的交互像这样

```c#

var klass = ass.GetType("App");
var method = klass.GetMethod("Update");
method.Invoke(null, new object[] {deltaTime});

```

这种方式的缺点是反射成本高，万一带参数，还有额外gc，其实完全有更高效的办法。主要有两种方式：

### 热更新层返回一个 Delegate

```c#

// 热更新部分 

class App
{

    public static Action<float> GetUpdateDelegate()
    {
        return Update;
    }

    public static void Update(float deltaTime)
    {
        
    }
}

// 主工程

var klass = ass.GetType("App");
var method = klass.GetMethod("GetUpdateDelegate");
var updateDel = (Action<float>)method.Invoke(null, null);

updateDel(deltaTime);

```

### 通过 Delegate.Create，根据MethodInfo创建相应的Delegate

```c#

var klass = ass.GetType("App");
var method = klass.GetMethod("Update");
updateDel = System.Delegate.CreateDelegate(typeof(Action<float>), null, method);
updateMethod(deltaTime);

```
