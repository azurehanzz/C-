#pragma once 
#include <iostream>
using namespace std;
//搜索二叉树
//增加节点 删除节点 查找节点 打印节点
template <class K>
struct BStreenode
{
	typedef BStreenode<K> Node;
	BStreenode(const K& val = 0)
		:_key(val),_left(nullptr),_right(nullptr)
	{
		;
	}
	K _key;
	Node* _left;
	Node* _right;
};
template <class K>
class BStree
{
	typedef BStreenode<K> Node;
public:
	BStree()
		:_root(nullptr){}
	bool insert(const K& val)
	{
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}
		Node* cur = _root;
		Node* parent = cur;
		while (cur)
		{
			if (val > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (val < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(val);
		if (parent->_key > val)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		return true;
	}
	bool find(const K& val)
	{
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key > val)
			{
				cur = cur->_left;
			}
			else if (cur->_key < val)
			{
				cur = cur->_right;
			}
			else
			{
				cout << "找到了" << endl;
				return true;
			}
		}
		return false;
	}
	void inprint()
	{
		_inprint(_root);
	}
	void _inprint(Node* node)
	{
		if (node==nullptr)
		{
			return;
		}
		_inprint(node->_left);
		cout << node->_key;
		_inprint(node->_right);
	}
	bool erase(const K& val)
	{
		Node* parent = _root;
		Node* cur = _root;
	/*	if (_root->_right == nullptr && _root->_left == nullptr)
		{
			delete cur;
			_root = nullptr;
			return true;
		}*/
		while (cur)
		{
			if (val > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (val < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				
				if (cur ->_left == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
					delete cur;
					return true;
				}
				else if (cur->_right == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_right == cur)
						{
							parent->_right = cur->_left;
						}
						else
						{
							parent->_left = cur->_left;
						}
					}
					delete cur;
					return true;
				}
				else
				{
					Node* rightmin = cur->_right;
					Node* min_parent = cur;
					while (rightmin->_left)
					{
						min_parent = rightmin;
						rightmin = rightmin->_left;
					}
					swap(cur->_key, rightmin->_key);
					if (min_parent->_right == rightmin)
					{
						min_parent->_right = rightmin->_right;
					}
					else
					{
						min_parent->_left = rightmin->_right;
					}

				}

			}
		}
		return false;
	}
private:
	Node* _root;
};