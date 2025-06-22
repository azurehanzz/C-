#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
//多态父类子类的析构(虚函数)  
//final 关键字,override关键字 
// 纯虚函数


//多态是如何实现的
//取虚表的地址(前四个字节)
//打印虚表,函数指针学习
class People
{
public:
	 virtual ~People()
	{
		cout << "~People" << endl;
	}
	virtual void print() 
	{
		cout << "全价购买" << endl;
	}
	void test()
	{
		cout << "people" << endl;
	}
protected:
	string _name;
};
class Student:public People 
{
public:
	virtual  ~Student()
	{
		cout << "~Student" << endl;
	}
	virtual void print() 
	{
		cout << "半价购买" << endl;
	}

	void test()
	{
		cout << "student" << endl;
	}
protected:
	int _id;
};
void test_multifunc()
{
	People* S_Ptr = new Student;
	People* P_Ptr = new People;
	delete S_Ptr;
	delete P_Ptr;

}  




class Base {
public:
	virtual void func1() { cout << "Base::func1" << endl; }
	virtual void func2() { cout << "Base::func2" << endl; }
private:
	int a;
};
class Derive :public Base {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
	virtual void func4() { cout << "Derive::func4" << endl; }
private:
	int b;
};
typedef void (*Ptr_func)();  //函数指针的表达 接受一个里面为空范围为空的一个函数指针

void print_VT()
{
	Derive d;
	Ptr_func* ptf = (Ptr_func *)*(int*)(&d);
	for (int i = 0; ptf[i] != NULL; i++)
	{
		printf("虚函数的地址为:%p", ptf[i]);
		ptf[i]();
		cout << endl;
	}
}



int main()
{

	print_VT();


	return 0;
}


