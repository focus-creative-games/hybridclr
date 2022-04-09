# libil2cpp.a 编译
## 设置环境变量

huatuo 编译需要的shell和cmake脚本依赖于下面两个环境变量。

* HUATUO_IL2CPP_SOURCE_DIR

* HUATUO_EXTERNAL_SOURCE_DIR


可以通过下面命令增加环境变量或将环境变量设置到 .bashrc 中。使用环境变量编译的好处在于编译过程中不必强行要求把拷贝移动libil2cpp目录，并且libil2cpp和external源码目录可以在不同的位置。

```shell
export HUATUO_IL2CPP_SOURCE_DIR=/Applications/Unity/Unity.app/Contents/il2cpp/
export HUATUO_EXTERNAL_SOURCE_DIR=/Applications/Unity/Unity.app/Contents/il2cpp/
```

## 编译il2cpp

编译过程部分步骤被合并到cmake脚本中，实际编译，只需要`cmake ..`和`make`两条命令即可

编译过程：

1. 设置环境变量
	
1. 执行gen_lump.sh 脚本**（此步骤被合并到 cmake 中，在编译完成自动执行）**
	该操作模拟il2cpp在windows下的编译过程，对il2cpp的子目录生成对应的lump文件。在lump文件中会包含`il2cpp-config.h`头文件，经测试发现，il2cpp源码编译若不生成lump文件直接编译会有部分报错；原因是因部分文件的头文件包含缺失导致这些文件中的宏定义出错，所以这里参考windows下的操作进行编译预处理
	
1. 创建编译目录，并进入目录
	
	```shell
	mkdir build
	cd build
	```

4. 执行编译命令

   ```shell
   cmake ..
   make j4
   ```
   静态库编译完成，生成文件libil2cpp_original.a和external/libzlib.a

5. 合并静态库文件**（此步骤被合并到 cmake 中，在编译完成自动执行）**
	```shell
	xcrun -r libtool -static -o libil2cpp.a libil2cpp_original.a external/libzlib.a
	```
	
6. 编译结束，生成 libil2cpp.a

## 待优化部分

当前编译方式问题：

	1. 当前cmake文件不能通过cmke客户端工具运行，只能通过脚本执行







