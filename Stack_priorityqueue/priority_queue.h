#pragma once
#include <iostream>
#include <vector>
using namespace std;
template <class T>
struct Less
{
	bool operator ()(const T& x1, const T& x2)
	{
		return x1 < x2;
	}
};
template <class T>
struct Greater
{
	bool operator ()(const T& x1, const T& x2)
	{
		return x1 > x2;
	}
};


template <class T, class Container = vector<T>, class compare =Greater<T>>
class priority_queue
{
public:
	void push(const T& val) {
		_con.push_back(val);
		Adjust_up(size()-1);
	
	};
	void pop() {
		swap(_con[0], _con[size() - 1]);
		_con.pop_back();
		Adjust_down(0);
	};
	T& top() {
		return _con.front();
	};
	int size() {
		return _con.size();
	};
	bool empty() {
		return _con.empty();
	};

	void Adjust_up(const size_t& point)
	{
		compare com;
		size_t parent = (point - 1) / 2;
		size_t child = point;
		while(child>0)
		{
			//if (_con[parent] < _con[child])
			if (com(_con[parent],_con[child]))
			{
				swap(_con[parent], _con[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
			{
				break;
			}
		}
	}
	void Adjust_down(const size_t& point)
	{
		compare com;
		size_t parent = point;
		size_t left_child = point * 2 + 1;
		size_t child = left_child+1;
		while(left_child<_con.size())
		{
			//if ((child > _con.size() - 1) || _con[child] < _con[left_child])
			if ((child > _con.size() - 1) || com(_con[child],_con[left_child]))
			{
				child = left_child;
			}

			//if (_con[child] > _con[parent])
			if(com(_con[parent],_con[child]))
			{
				swap(_con[child], _con[parent]);
			}
			else
			{
				break;
			}
			parent = child;
			left_child = 2 * parent + 1;
			child = left_child+1;
		}
		

	}



private:
	Container _con;
};