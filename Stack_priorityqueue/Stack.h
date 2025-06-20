#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <class T,class container>
class Stack
{
public:
	typedef container _con;
	Stack()
	{
	}
	void push(const T& val)
	{
		con.push_back(val);
	}
	T& top()
	{
		return con.back();
	}
	void pop()
	{
		con.pop_back();
	}
	bool empty()
	{
		return con.empty();
	}

private:
	_con con;
};
