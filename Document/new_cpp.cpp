class Foo
{
public:
	Foo() : _id(0)
	{
		cout << "default constructor. id = " << _id << endl;
	}
	Foo(int i) : _id(i)
	{
		cout << "constructor. id = " << _id << endl;
	}
	~Foo()
	{
		cout << "destructor. id = " << _id << endl;
	}

	//一般的 operator new 重载
	void* operator new(size_t size)
	{
		cout << "normal operator new." << endl;
		return malloc(size);
	}

	//标准库已经提供的 placement new() 的重载形式
	void* operator new(size_t size, void* start)
	{
		cout << "normal placement new" << endl;
		return start;
	}

	//新的 placement new() 重载形式1
	void* operator new(size_t size, long extra)
	{
		cout << "overloading operator new 1st." << endl;
		return malloc(size);
	}

	//新的 placement new() 重载形式2
	void* operator new(size_t size, long extra, char init)
	{
		cout << "overloading operator new 2nd." << endl;
		return malloc(size);
	}

private:
	int _id;
	long _data;
	string _str;
};

void main()
{
	char *pt = new char[sizeof(Foo)];
	//一般的 placement new()，先分配内存，然后构造 Obj
	Foo* pf = new(pt)Foo;
	
	// placement new 重载形式1
	Foo* pf1 = new(1)Foo(10);
	
	//placement new 重载形式2
	Foo* pf2 = new(2, 'c')Foo(20);

	delete pf;
	delete pf1;
	delete pf2;

	system("pause");
}
