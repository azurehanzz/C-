#define _CRT_SECURE_NO_WARNINGS
#include "BStree.hpp"
#include <string>
typedef BStreenode<int, int> Node;
class Solution {
public:
    static string tree2str(Node* root ) {
        string s;
        if (root != nullptr)
        {
            s += to_string(root->_key);
            if (root->_left)
            {
                s += '(';
                s += tree2str(root->_left);
                s += ')';   
            }
            else if (root->_right)
            {
                s += "()";
            }
            if (root->_right)
            {
                s += '(';
                s += tree2str(root->_right);
                s += ')';
            }

        }
        return s;

    }
};

void Test_tree2str()
{
    Node *root1 =new Node(1);
    Node *root2 =new Node(2);
    Node *root3 =new Node(3);
    Node *root4 =new Node(5);
    Node *root5 =new Node(6);
    root1->_left = root2;
    root1->_right = root3;
    root2->_left = root4;
    root4->_right = root5;
    string s = Solution::tree2str(root1);
    cout << s;
    
    
}
int main()
{
    Test_tree2str();
	return 0;
}