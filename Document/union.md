在构造union时，编译器只负责分配空间，而不负责去执行附加的初始化工作，为了简化工作，只要我们提供了构造函数，就会收到上面的error。
同理，除了不能加构造函数，析构函数/拷贝构造函数/赋值运算符也是不可以加。

此外，如果我们的类中包含了任何virtual函数，编译时，我们将收到如下的错误信息:
	
	error C2621: union '__unnamed' : member 'obj' has copy constructor

所以，打消在union中包含有`构造函数/析构函数/拷贝构造函数/赋值运算符/虚函数的类成员变量`的念头，老老实实用你的C风格struct吧!

union是个好东西，union是个struct，里面所有成员共享一块内存，大小由size最大的member决定，
存取成员的时候会以成员的类型来解析这块内存；

如何说明？
联合变量的说明有三种形式：先定义再说明、定义同时说明和直接说明。

以test类型为例，说明如下：

	1)union test
	{
	  int office;
	  char teacher[5];
	};
	union test a,b; /*说明a,b为test类型*/
	
	
	2) union test
	{
	  int office;
	  char teacher[5];
	} a,b;
	
	
	3)
	union
	{
	  int office;
	  char teacher[5];
	} a,b;
	

	
1.同一个内存段可以用来存放几种不同类型的成员，但在每一个时刻只能存在其中一种，而不是同时存放几种。
也就是说，每一瞬间只有一个成员起作用，其它的成员不起作用，即不是同时都存在和起作用。

2.共用体变量中起作用的成员是最后一个存放的成员，在存入一个新的成员后，原有的成员就失去作用。

3.由于union中的所有成员起始地址都是一样的，所以&a.mark、&a.num和&a.score的值都是一样的。

4.不能把union变量作为函数参数，也不能使函数带回union变量，但可以使用指向union变量的指针。

5.union类型可以出现在结构体类型定义中，也可以定义union数组，反之，结构体也可以出现在union类型定义中，数组也可以作为union的成员。


6 union在协议开发中的用法

	union的一个常用用法是：
	
		typedef union
		{
		    unsigned int Ax;
		    struct AX
		    {
		        unsigned int AL:16;
		        unsigned int AH:16;
		    }sAX;
		}example;
	
		
	改结构 ，可以表示一个整体，又可以表示成高位和低位的组合 。这个是union在协议开发中的一个常用的 用法


