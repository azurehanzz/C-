#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

template <class T>
struct _listnode
{
	typedef _listnode<T> Node;
	
	_listnode(T data = T())
		:_data(data),_pre(nullptr),_next(nullptr)
	{}
	T _data;
	Node* _pre;
	Node* _next;
};
template <class T,class Ref,class Ptr >
struct _iterator
{
	typedef _listnode<T> Node;
	typedef _iterator<T, Ref, Ptr> Self;
	_iterator(Node* node)
		:_node(node)
	{}
	Self& operator ++ ()
	{
		_node = _node->_next;
		return *this;
	}

	Self operator++(int)
	{
		Self tmp(_node);
		_node = _node->_next;
		return tmp;
	}
	Self& operator --()
	{
		_node = _node->_pre;
		return *this;
	}
	Self operator --(int)
	{
		Self tmp(_node);
		_node = _node->_pre;
		return tmp;
	}
	Ref operator *()
	{
		return _node->_data;
	}
	bool operator != (Self it)
	{
		return _node != it._node;
	}
	Ptr operator ->()
	{
		return &(_node->_data);
	}
	Node* _node;
};
template<class T>
class list
{
	typedef _listnode<T> Node;
public:
	typedef _iterator<T,T&,T*> iterator;
	typedef _iterator<T, const T&, const T*> const_iterator;
	list(const T& data=T())
		:_head(new Node)
	{
		_head->_data = data;
		_head->_next = _head;
		_head->_pre = _head;
	}
	~list()
	{
		iterator it = begin();
		while (it != end())
		{
		    it = erase(it);
		}
		cout << "erase结束" << endl;
		delete _head;
		cout << "head也删除成功" << endl;
	}

	list(const list<T>& ls)
	{
		const_iterator it = ls.begin();
		_head = new Node;
		_head->_next = _head;
		_head->_pre = _head;
		while (it != ls.end())
		{
			push_back(*it);
			it++;
		}
	}
	
	list<T>& operator = (list<T> ls)
	{
		swap(_head, ls._head);
		return *this;
	}
	void push_back(const T& data)
	{
		Node* n1 = new Node;
		n1->_data = data;
		Node* tail = _head->_pre;
		tail->_next = n1;
		n1->_next = _head;
		_head->_pre = n1;
		n1->_pre = tail;
	}
	iterator begin()
	{
		return iterator(_head->_next);
	}

	const_iterator begin() const
	{
		return const_iterator(_head->_next);
	}
	
	iterator end()
	{
		return iterator(_head);
	}

	const_iterator end() const
	{
		return const_iterator(_head);
	}
	void print() const
	{
		const_iterator it =  begin();
		while (it != end())
		{
			cout << *it;
			it++;
		}
		cout << "end" << endl;
	}
	iterator insert(const int& pos,const T& val)
	{
		if(pos < length())
		{
			Node* tmp = _head;
			for (int i = 0; i < pos; i++)
			{
				tmp = tmp->_next;
			}
			Node* newnode = new Node;
			newnode->_data = val;
			Node* nextnode = tmp->_next;
			newnode->_next = nextnode;
			nextnode->_pre = newnode;
			tmp->_next = newnode;
			newnode->_pre = tmp;
			return iterator(newnode);
		}
		else
		{
			push_back(val);
			return iterator(_head->_pre);
		}
	}

	iterator insert(iterator& it, const T& val)
	{
		assert(it._node);
		Node* tmp = it._node;

		Node* newnode = new Node;
		newnode->_data = val;
		Node* nextnode = tmp->_next;
		newnode->_next = nextnode;
		nextnode->_pre = newnode;
		tmp->_next = newnode;
		newnode->_pre = tmp;
		return iterator(tmp);
	}

	iterator erase(iterator& it)
	{
		assert(it != end());
		{
			Node* tmp =it._node;
			Node* pre = tmp->_pre;
			Node* next = tmp->_next;
			pre->_next = next;
			next->_pre = pre;
			delete tmp;
			return iterator(next);
		}
	}
	int length()
	{
		int count = 0;
		iterator it(_head->_next);
		while (it++!= end())
		{
			count++;
		}
		return count;
	}
private:
	Node* _head;
};