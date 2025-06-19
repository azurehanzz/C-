#define _CRT_SECURE_NO_WARNINGS
#include "List_1.h"


void Test_list1()
{
	list<int> l1;
	l1.push_back(1);
	l1.push_back(1);
	l1.push_back(1);
	l1.push_back(1);
	l1.push_back(1);

	l1.print();
}

void Test_list2()
{
	struct Date
	{
		int year = 1;
		int month = 1;
		int day = 1;
	};
	Date d1;
	Date d2;
	list<Date> l1;
	l1.push_back(d1);
	l1.push_back(d2);

	list<Date> ::iterator it = l1.begin();
	while (it != l1.end())
	{
		cout << it->year << "-" << it->month << "-" << it->day << "-" << endl;
		++it;
	}

}


void Test_list3()
{
	list<int> l1(0);
	l1.push_back(1);
	l1.push_back(1);
	l1.push_back(1);
	l1.push_back(1);
	list<int>::iterator it = l1.insert(3, 4);
	l1.insert(it, 5);
	l1.print();


}

void Test_list4()
{
	list<int> l1(0);
	l1.push_back(1);
	l1.push_back(1);
	l1.push_back(1);
	l1.push_back(1);
	list<int>::iterator it = l1.insert(3, 4);
	l1.insert(it, 5);
	l1.print();

	l1.print();


}


void Test_list5()
{
	list<int> l1(0);
	l1.push_back(1);
	l1.push_back(1);
	l1.push_back(1);
	l1.push_back(1);
	l1.print();

	list<int> l2(l1);
	l2.print();
	list<int> l3;
	l3 = l1;
	l3.print();

}

int main()
{
	Test_list5();
	return 0;
}