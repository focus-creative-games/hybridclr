# 性能测试

网上流行的性能测试用例构造极其不合理，但为了避免人为构造用例之嫌，huatuo仍然选择了第三方的性能测试用例 [UnityScriptPTest](https://github.com/cateatcatx/UnityScriptPTest)。

我们后面会重新发布比较合理的测试用例下的性能对比结果。

测试示例项目地址(TODO,马上提交)。

## benchmark

与其他第三方c#热更新方案的测试数据，我们今天晚些时候更新。

测试数据是 win 10下pc平台的测试结果，IOS测试数据随后更新。

从测试数据来看，除了数值计算略慢于xlua（原因是目前完全未对基础指令优化，例如a=b+c需要4条指令，在5月份版本将会优化，大多数指令都有100%-300%的提升），其他大幅胜出。


| ID   | Name  | 接口调用次数 | huatuo总耗时(ms) | xlua总耗时(ms) | huatuo/xlua |
| ---- | ----- | ------------ | ---------------- | -------------- | ----------- |
| 1    | Test0 | 2            | 23               | 172            | 0.1337      |
| 2    | Test1 | 2            | 56               | 198            | 0.2828      |
| 3    | Test2 | 2            | 181              | 2885           | 0.0627      |
| 4    | Test3 | 2            | 74               | 120            | 0.6167      |
| 5    | Test4 | 2            | 165              | 359            | 0.4596      |
| 6    | Test5 | 2            | 11               | 389            | 0.0283      |
| 7    | Test6 | 2            | 19               | 238            | 0.0798      |
| 8    | Test7 | 2            | 84               | 468            | 0.1795      |
| 9    | Test8 | 2            | 68               | 61             | 1.1148      |
| 10   | Test9 | 2            | 22398            | 18372          | 1.2191      |

## 测试代码

```lua
local UnityEngine = CS.UnityEngine
local up = UnityEngine.Vector3.up
local GameObject = UnityEngine.GameObject
local SkinnedMeshRenderer = UnityEngine.SkinnedMeshRenderer
local Vector3 = UnityEngine.Vector3
local Quaternion = UnityEngine.Quaternion
local Normalize = UnityEngine.Vector3.Normalize
local Input = UnityEngine.Input
local UserClass = CS.UserClass


_V0 = 1
_V1 = "12345"
_V2 = GameObject()
_V3 = Vector3(1, 2, 3)
_V4 = {1, 2, 3}


function EmptyFunc()
end

function GetV0()
    return _V0
end

function GetV1()
    return _V1
end

function GetV2()
    return _V2
end

function GetV3()
    return _V3
end

function GetV4()
    return _V4
end

function GC()
 collectgarbage()
end

function Version()
 print(jit.version)
end


function Test0(transform) 
 local t = os.clock()
 
 for i = 1,200000 do
  transform.position = transform.position
 end
 
 return os.clock() - t
end

function Test1(transform)   
 local t = os.clock()
 for i = 1,200000 do
  transform:Rotate(up, 1) 
 end
 
 return os.clock() - t
end

function Test2() 
 local t = os.clock()
 
 for i = 1, 2000000 do
  local v = Vector3(i, i, i)
  local x,y,z = v.x, v.y, v.z
 end
  
 return os.clock() - t
end

--会存在大量gc操作
function Test3()
 local t = os.clock() 

 for i = 1,20000 do    
  GameObject()
 end
 
 return os.clock() - t
end

function Test4() 
 local t = os.clock()
 local tp = typeof(SkinnedMeshRenderer)

 for i = 1,20000 do    
  local go = GameObject()
  go:AddComponent(tp)
     local c = go:GetComponent(tp)
     c.receiveShadows=false
 end
  
 return os.clock() - t
end

function Test5()
 local t = os.clock()
 
 for i = 1,200000 do  
  local p = Input.mousePosition
  --Physics.RayCast
 end
  
 return os.clock() - t
end

function Test6() 
 local Vector3 = Vector3 
 local t = os.clock()
  
 for i = 1, 200000 do
  local v = Vector3(i,i,i)
  Vector3.Normalize(v)
 end
  
 return os.clock() - t
end

function Test7()  
 local Quaternion = Quaternion
 local t = os.clock()
 
 for i=1,200000 do
  local q1 = Quaternion.Euler(i, i, i)  
  local q2 = Quaternion.Euler(i * 2, i * 2, i * 2)
  Quaternion.Slerp(Quaternion.identity, q1, 0.5)  
 end
  
 return os.clock() - t
end

function Test8()
 local total = 0
 local t = os.clock()

 for i = 0, 1000000, 1 do
  total = total + i - (i/2) * (i + 3) / (i + 5)
 end

 return os.clock() - t 
end

function Test9()
 local array = {}

 for i = 1, 1024 do
  array[i] = i
 end

 local total = 0
 local t = os.clock()
  
 for j = 1, 100000 do
  for i = 1, 1024 do
   total = total + array[i]
  end   
 end
  
 return os.clock() - t
end

function Test10(trans)
 local t = os.clock()
 
 for i = 1, 200000 do
  UserClass.TestFunc1(1, "123", trans.position, trans)
 end 
  
 return os.clock() - t
end


```

```c#

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using UnityEngine;

public class TestFunc
{
    public static int _v0 = 3;
    public static string _v1 = "12345";
    public static GameObject _v2 = new GameObject();
    public static Vector3 _v3 = new Vector3(1, 2, 3);
    public static List<int> _v4 = new List<int>() { 1, 2, 3 };

    public static void EmptyFunc()
    {

    }


    public static Action CreateEmptyDel()
    {
        return EmptyFunc;
    }

    public static Func<int> CreateV0Del()
    {
        return Get_V0;
    }

    public static Func<string> CreateV1Del()
    {
        return Get_V1;
    }

    public static Func<GameObject> CreateV2Del()
    {
        return Get_V2;
    }

    public static Func<Vector3> CreateV3Del()
    {
        return Get_V3;
    }

    public static Func<List<int>> CreateV4Del()
    {
        return Get_V4;
    }

    public static int Get_V0()
    {
        return _v0;
    }
    public static string Get_V1()
    {
        return _v1;
    }
    public static GameObject Get_V2()
    {
        return _v2;
    }
    public static Vector3 Get_V3()
    {
        return _v3;
    }
    public static List<int> Get_V4()
    {
        return _v4;
    }
    public static double Test0(UnityEngine.Transform trans)
    {
        long ts = System.DateTime.Now.Ticks;
        for (int i = 0; i < 200000; i++)
        {
            trans.position = trans.position;
        }
        double t = (double)((System.DateTime.Now.Ticks - ts) / 10000.0);
        return t;
    }
    public static double Test1(UnityEngine.Transform t)
    {
        long ts = System.DateTime.Now.Ticks;
        var up = Vector3.up;
        for (int i = 0; i < 200000; i++)
        {
            t.Rotate(up, 1);
        }
        double dt = (double)((System.DateTime.Now.Ticks - ts) / 10000.0);
        return dt;
    }
    public static double Test2()
    {
        long ts = System.DateTime.Now.Ticks;
        for (int i = 0; i < 2000000; i++)
        {
            var v = new UnityEngine.Vector3(i, i, i);
            var x = v.x;
            var y = v.y;
            var z = v.z;
        }
        double t = (double)((System.DateTime.Now.Ticks - ts) / 10000.0);
        return t;
    }
    public static double Test3()
    {
        long ts = System.DateTime.Now.Ticks;
        for (int i = 0; i < 20000; i++)
        {
            var obj = new GameObject();
        }
        double t = (double)((System.DateTime.Now.Ticks - ts) / 10000.0);
        return t;
    }
    public static double Test4()
    {
        long ts = System.DateTime.Now.Ticks;
        var tp = typeof(SkinnedMeshRenderer);
        for (int i = 0; i < 20000; i++)
        {
            var go = new GameObject();
            go.AddComponent(tp);
            var c = go.GetComponent(tp) as SkinnedMeshRenderer;
            c.receiveShadows = true;
        }
        double t = (double)((System.DateTime.Now.Ticks - ts) / 10000.0);
        return t;
    }
    public static double Test5()
    {
        long ts = System.DateTime.Now.Ticks;
        for (int i = 0; i < 200000; i++)
        {
            var p = Input.mousePosition;
            //--Physics.RayCast;
        }
        double t = (double)((System.DateTime.Now.Ticks - ts) / 10000.0);
        return t;
    }
    public static double Test6()
    {
        long ts = System.DateTime.Now.Ticks;
        for (int i = 0; i < 200000; i++)
        {
            var v = new Vector3(i, i, i);
            Vector3.Normalize(v);
        }
        double t = (double)((System.DateTime.Now.Ticks - ts) / 10000.0);
        return t;
    }
    public static double Test7()
    {
        long ts = System.DateTime.Now.Ticks;
        for (int i = 0; i < 200000; i++)
        {
            var q1 = Quaternion.Euler(i, i, i);
            var q2 = Quaternion.Euler(i * 2, i * 2, i * 2);
            Quaternion.Slerp(Quaternion.identity, q1, 0.5f);
        }
        double t = (double)((System.DateTime.Now.Ticks - ts) / 10000.0);
        return t;
    }
    public static double Test8()
    {
        long ts = System.DateTime.Now.Ticks;
        int total = 0;
        for (int i = 0; i < 1000000; i++)
        {
            total = total + i - (i / 2) * (i + 3) / (i + 5);
        }
        double t = (double)((System.DateTime.Now.Ticks - ts) / 10000.0);
        return t;
    }
    public static double Test9()
    {
        int[] array = new int[1024];
        for (int i = 0; i < 1024; i++)
        {
            array[i] = i;
        }
        int total = 0;
        long ts = System.DateTime.Now.Ticks;
        for (int i = 0; i < 100000; i++)
        {
            for (int j = 0; j < 1024; j++)
            {
                total = total + array[j];
                total = total + array[j];
                total = total + array[j];
                total = total + array[j];
                total = total + array[j];
                total = total + array[j];
                total = total + array[j];
                total = total + array[j];
                total = total + array[j];
                total = total + array[j];
            }
        }
        double t = (double)((System.DateTime.Now.Ticks - ts) / 10000.0);
        return t;
    }
    public static double Test10(Transform trans)
    {
        long ts = System.DateTime.Now.Ticks;
        for (int i = 0; i < 200000; i++)
        {
            UserClass.TestFunc1(1, "123", trans.position, trans);
        }
        double t = (double)((System.DateTime.Now.Ticks - ts) / 10000.0);
        return t;
    }
}


```
