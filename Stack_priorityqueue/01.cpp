#define _CRT_SECURE_NO_WARNINGS
#include "priority_queue.h"
using namespace std;
//bool IsPopOrder(const vector<int>& pushV, const vector<int>& popV) {
//	stack<int> s1;
//	stack<int> s2;
//	for (int j = popV.size()-1; j >= 0; j--)
//	{
//		s2.push(popV[j]);
//	}
//	for (int i = 0; i < pushV.size(); i++)
//	{
//		s1.push(pushV[i]);
//		while (s1.top() == s2.top())
//		{
//			s1.pop();
//			s2.pop();
//			if (s1.empty() || s2.empty())
//			{
//				break;
//			}
//		}
//	}
//
//
//	return s1.empty();
//
//}
//void test_IsPopOrder()
//{
//	vector<int> v1;
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	v1.push_back(5);
//	vector<int> v2;
//	v2.push_back(1);
//	v2.push_back(4);
//	v2.push_back(3);
//	v2.push_back(5);
//	v2.push_back(2);
//	cout << IsPopOrder(v1, v2) << endl;
//}
//void test_string()
//{
//
//	string s1("123");
//	cout<<stoi(s1);
//}
//int evalRPN(vector<string>& tokens) {
//	stack<int> s1;
//	for (int i = 0; i < tokens.size(); i++)
//	{
//		if ((tokens[i] != "+") && (tokens[i] != "-") && (tokens[i] != "*") && (tokens[i] != "/"))
//		{
//			s1.push(stoi(tokens[i]));
//		}
//		else
//		{
//			int right = s1.top();
//			s1.pop();
//			int left = s1.top();
//			s1.pop();
//			switch (tokens[i][0])
//			{
//			case '+':
//				s1.push(right + left);
//				break;
//			case '-':
//				s1.push(left - right);
//				break;
//			case '*':
//				s1.push(left * right);
//				break;
//			case '/':
//				s1.push(left / right);
//				break;
//			}
//
//
//		}
//
//	}
//	return s1.top();
//}
//void test_evalRPN()
//{
//	vector<string> str;
//	str.push_back("4");
//	str.push_back("13");
//	str.push_back("5");
//	str.push_back("/");
//	str.push_back("+");
//	cout<<evalRPN(str);
//}


//void test_stack()
//{
//	Stack<int, vector<int>> st;
//	st.push(1);
//	st.push(1);
//	st.push(1);
//	st.push(1);
//	while (!st.empty())
//	{
//		cout << st.top() << endl;
//		st.pop();
//	}
//}

void test_priority_queue()
{
	priority_queue<int> pq;
	pq.push(1);
	pq.push(2);
	pq.push(3);
	pq.push(5);
	pq.push(7);
	pq.push(4);
	while (!pq.empty())
	{
		cout << pq.top();
		pq.pop();
	}
}
int main()
{

	test_priority_queue();

	return 0;
}