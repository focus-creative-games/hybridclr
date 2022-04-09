# il2cpp bug记录

## 逆变协变泛型接口调用错误

查找obj的interface实现有误，按规范以下代码应该打出"Comput B"，例如.net 6是这个结果，但mono和il2cpp下却打印出"Comput A"。

```c#

interface ITest<out T>
{
    T Comput();
}

class A : ITest<object>
{
    public object Comput()
    {
        return "Comput A";
    }
}

class B : A, ITest<string>
{
    public string Comput()
    {
        return "Comput B";
    }
}

class App
{
    public static void Main()
    {
        ITest<object> f = new B();
        Debug.Log(f.Comput());
    }
}

```

## obj.Func() 非虚调用不符合规范

ECMA规范允许对null使用call指令进行非虚调用，但il2cpp却在调用前插入了NullCheck操作。导致以下代码在mono下会打印出 "hello"，而在il2cpp下抛了NullReferenceException。

```c#

class TestNull
{
    public void Show()
    {
        Debug.Log("hello");
    }
}

class App
{
    public void Main()
    {
        TestNull nu = null;
        nu.Show();
    }
}

```
