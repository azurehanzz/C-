#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
//ģ���ػ�
//���ػ�,�����ػ�
//���� ����̳� ��������๹�캯��+��������
//��������
//���μ̳е�����Ͷ�����,��̳�

//��̬�������������(�麯��)  
//final �ؼ���,override�ؼ��� 
// ���麯��
template <class T,class ptr>
class Date
{
public:
	void print()
	{
		cout << "���ػ�����" << endl;
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
		cout << "�ػ�����" << endl;
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
bool isequal<char*>(  char* const  & val1,  char* const & val2)//ע��:��ָ������T=char*ʱ��constӦ������ָ�����壨char* const��������ָ��ָ������ݣ�const char*��
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