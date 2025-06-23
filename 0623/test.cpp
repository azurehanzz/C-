#include "BStree.hpp"
//
//class A
//{
//public:
//	void func(int val = 1) { std::cout << "A->" << val << std::endl; }
//	virtual void test() { func(); }
//};
//class B :virtual public A
//{
//public:
//	virtual void func(int val = 0) { std::cout << "B->" << val << std::endl; }
//};
//int main(int argc, char* argv[])
//{
//	B* b = new B;
//	cout << sizeof(B);
//	printf("%p", *((int*)&(*b) + 1));
//	int* val = new int;
//	*val = 10;
//	printf("%p", val);
//	return 0;
//}



int main()
{
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	BStree<int> t;
	for (auto i : a)
	{
		t.insert(i);
	}
	t.inprint();
	for (auto i : a)
	{
		t.erase(i);
		t.inprint();
		cout << endl;
	}
	cout << endl;
	
	return 0;
}

