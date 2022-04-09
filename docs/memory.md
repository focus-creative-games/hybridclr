# huatuo内存占用

huatuo是运行时级别的实现，因为热更新的脚本，除了执行代码是以解释模式执行，其他方式跟AOT部分的类型是完全相同的，包括占用内存。因此下面只介绍il2cpp中class类型和ValueType类型对象的内存大小情况。

## 对象内存大小

对于值类型，对象大小并不是简单为所有成员所占大小，必须考虑到内存对齐。对于引用类型，多了额外了对象头(16字节)，并且内存对齐为8字节。对于array类型，则更为复杂。

### primitive type 如byte,int

如熟知， byte占1字节,int占4字节，其他不赘述。

### 普通ValueType对象大小

在未指定ExplicitLayout的情况下，根据字段大小及内存对齐规则计算出总大小，与c++的struct计算规则相似。这里不详细阐述，直接举例吧

```c#

struct V1
{
    public byte a1;
}

struct V2
{
    public byte a1;
    public int a2;
}

struct V3
{
    public int a1;
    public int a2;
    public object a3;
    public byte a4;
}
```

以上对象的对象大小为：

- V1 1
- V2 8
- V3 24

## class 类型内存占用

与 ValueType相似，但多了对象头的16字节，并且强制内存对齐为8字节。

示例:

```c#
class C1
{
    public byte a1;
}

class C2
{
    public byte a1;
    public int a2;
}

class C3
{
    public int a1;
    public int a2;
    public object a3;
    public byte a4;
}
```

以上对象大小为

- C1 24
- C2 24
- C3 40

## 对象内存大小对比

lua的计算规则略复杂，参见[第三方文章](https://www.linuxidc.com/Linux/2018-10/154971.htm)。空table占56字节，每多一个字段至少多占32字节。

ILRuntime的类型除了enum外统一以IlTypeInstance表达，空类型占72字节，每多一个字段至少多用16字节。如果对象中包含引用类型数据，则整体又至少多24字节，并且每多一个object字段多8字节。

|类型 | Xlua | ILRuntime | huatuo |
|-| -| -| -|
|V1|88| 88 | 1|
|V2|120|104|8|
|V3|184|168|24|
|C1|88| 88 | 24|
|C2|120|104|24|
|C3|184|168|40|
