#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
//模板特化
//类特化,函数特化
//父类 子类继承 子类调父类构造函数+拷贝构造
//函数隐藏
//菱形继承的冗余和二义性,虚继承

//多态父类子类的析构(虚函数)  
//final 关键字,override关键字 
// 纯虚函数
template <class T,class ptr>
class Date
{
public:
	void print()
	{
		cout << "无特化函数" << endl;
	}
private:
	T _date;
	ptr _data;
};
template <class ptr>
class Date<double,ptr>
{
public:
	void print()
	{
		cout << "特化函数" << endl;
	}
private:
	double _date;
};
template <class T >
bool isequal(const T& val1, const T& val2)
{
	return val1 == val2;
}
template <>
bool isequal<char*>(  char* const  & val1,  char* const & val2)//注意:对指针类型T=char*时，const应作用于指针整体（char* const），而非指针指向的数据（const char*）
{
	return strcmp(val1, val2) == 0;
}
void Test_personality_func()
{
	Date<int,double>d1;
	d1.print();
	Date<double,int>d2;
	d2.print();
	cout << isequal(1, 2) << endl;
	cout << isequal("123", "123") << endl;
}
class person
{
public:
	person(int age=10, string name = "peter")
		:_age(age), _name(name)
	{

	}
	void print()
	{
		cout << _age << endl;
		cout << _name << endl;
	}
protected:
	int _age ;
	string _name ;
};
class teacher:virtual public person
{
public:
	teacher(int age=0)
		:person(age, "mary"), _age(age)
	{

	}
	void print()
	{
		cout << person::_age << endl;
		cout << _age << endl;
		cout << _name << endl;
	}
protected:
	int _age;
};
class student :virtual public person
{
public:
	student(int age = 0)
		:person(age, "mary"), _age(age)
	{

	}
	void print()
	{
		cout << person::_age << endl;
		cout << _age << endl;
		cout << _name << endl;
	}
protected:
	int _age;
};
class mary :public student,public teacher
{
protected:
	int idcard=1;
};
class add
{
public:
	virtual int add_num(int x1, int x2)
	{
		return x1 + x2;
	}
};
void Test_person_techer()
{
	teacher t;
	person p;
	t.print();
	p.print();
}
void Test_person_teacher_student_name()
{
	mary m;
}
void Test_virtual_func()
{
	add a;
	cout<<a.add_num(1, 2);
}
int main()
{
	//Test_personality_func();
	//Test_person_techer();
	//Test_virtual_func();

	return 0;
	
}