# DataStructure

学习数据结构的源码封装分享，提高学习效率

包含可直接运行的实例，C和C++实现的各种数据结构头文件封装，一些常用的小函数功能

一起享受学习数据结构的快乐吧！



## Usage

#### Download and Import

下载源码文件

安装了`Git`的同学可以 `git clone` 或者 直接点击 `Download Zip`

将整个文件夹(zip就先解压)添加到项目中



#### Running

可以直接在 main.cpp 或者 	classEntry.cpp 文件下Running，两者均包含实例

如果你的编译器配置暂只允许一个mian函数入口，可保留一个上面中任意文件

其中 main.cpp 调用纯函数包装的数据结构，C混合C++编写，输入输出和引用使用CPP

classEntry.cpp 调用类封装好的数据结构，使用了更多C++特性，用起来也更简便


#### Note

使用线性表(main.cpp)	

```cpp
// 包含所需结构的头文件即可调用
#include "lzystructure/linearList.h"

int main(){
	// 使用头文件中的类型定义和方法，名称和描述见具体文件
	linearList * L;
	int a[]={1,2,3,4,5,6,7,8,9,0};
	// 使用数组初始化线性表
	createList(L,a,10);
	cout<<"是否是空："<<listEmpty(L);
	// 插入元素 666 和 2333
	insertElem(L, 0, 666);
	insertElem(L, 1, 2333);
	cout<<"是否是空："<<listEmpty(L);
	deleteElem(L,0);
	打印结构
	printList(L);
	destroyList(L);
	// system("pause");
}

```

#### 函数方法表

> 函数名/方法名 大多与清华大学出版社李春葆教授主编的数据结构教材命名保持一致

请注意：增删改查使用的计数方式均从0开始，这点与教材有出入

`[name]` 代表对应结构的名称，如：顺序表 - linear， 链表 - link ... 

*仅线性表做示例，其余数据结构请查看头文件源码*

|  函数/方法名  | 描述                                                  |
| :-----------: | ----------------------------------------------------- |
|  init<name>   | 初始化空的结构                                        |
| destroy<name> | 销毁该数据结构                                        |
| create<name>  | 使用数据初始化一个机结构                              |
|  insertElem   | 插入元素到index位置上                                 |
|  deleteElem   | 删除index位置的元素                                   |
|    getElem    | 通过index获取元素                                     |
|  locateElem   | 查找元素的index                                       |
|  <name>Empty  | 是否为空值，返回bool值                                |
|  print<name>  | 打印输出改该数据结构，可自己重新定义                  |
| <name>Length  | 返回改结构长度                                        |
|     sort      | 排序结构，使用`algorithm/sorts.h`文件中的排序算法排序 |
|    reverse    | 倒序结构                                              |


### 工程目录

-- DataStructure

	-- main.cpp
	-- classEntry.cpp
	-- lzystructure
		-- linearList.h
		-- linkList.h
		-- ...
		
	-- lzyclass
		-- LinearList.h
		-- LinkList.h
		-- ...

	-- algorithm
		-- sorts.h
		-- ...

每个数据结构类型对应一个类封装头文件一个函数包装头文件。

算法分类放在algorithm文件夹下




### 预计完成的数据结构

- 线性表之顺序表（已完成）

- 线性表之链表（ing）

- 栈

- 队列

- 串

- 二叉树



### 预计完成Copy的算法实例

- 排序
	- 冒泡排序
	- 快速排序
	- 插入排序

- 查找
	- 二分法
	- Brute-Force算法
	- KMP算法

……待更新



## More

本项目工程量不少，C实现后还需C++实现一遍，项目还需不断开发和完善，加入我们一起?

Email Lozyue: lozyue@foxmail.com

PS:

不熟悉数据结构没关系，提前看书先过一遍懂个隐隐约约就跟着书去敲，纸上得来终觉浅嘛。
悄悄的说：目前这一些我也是跟着书上敲再整合修改的。
这个项目就是用来学习的，同时也希望能反过来促进学习，清理思路。

没写过头文件没关系，头文件和普通文件大同小异，模仿即可。

此外在用C++重新实现的过程中还能反复练习，加强理解记忆。
不了解怎么写C++也没关系，C++本人也不太会，边学边用，要什么再学什么。

同学同道，终生相习。代码如诗，只要你也喜欢追求美，那就加入我们共同进步吧！

开发过程见开发README，位于`lzystructure`和`lzyclass`文件夹下	
