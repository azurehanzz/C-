#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution 
{
public:
    static vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> vv;
        vector<int> v;
        queue<TreeNode*> q;
        if (root)
        {
            q.push(root);
            while (!q.empty())
            {
                int sz = q.size();
                for(int i=0;i<sz;i++)
                {
                    v.push_back(q.front()->val);
                    if (q.front()->left)
                    {
                        q.push(q.front()->left);
                    }
                    if (q.front()->right)
                    {
                        q.push(q.front()->right);
                    }
                    q.pop();
                }
                vv.push_back(v);
                v.clear();
            }
             
        }
        return vv;
    }
    static vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> vv;
        vector<int> v;
        stack<vector<int>> s;
        queue<TreeNode*> q;
        if (root)
        {
            q.push(root);
            while (!q.empty())
            {
                int sz = q.size();
                for (int i = 0; i < sz; i++)
                {
                    v.push_back(q.front()->val);
                    if (q.front()->left)
                    {
                        q.push(q.front()->left);
                    }
                    if (q.front()->right)
                    {
                        q.push(q.front()->right);
                    }
                    q.pop();
                }
                s.push(v);
                v.clear();
            }
            while (!s.empty())
            {
                vv.push_back(s.top());
                s.pop();
           }

        }
        return vv;

    }
    static TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> s;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            if (find_Node(que.front(), p) && find_Node(que.front(), q))
            {
                s.push(que.front());
            }
            if (que.front()->left)
            {
                que.push(que.front()->left);
            }
            if (que.front()->right)
            {
                que.push(que.front()->right);
            }
            que.pop();
        }
        return s.top();
    }

    static bool find_Node(TreeNode* root, TreeNode* val)
    {
        if (root == val)
        {
            return true;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            if (q.front() == val)
            {
                return true;
            }
            if (q.front()->right)
            {
                q.push(q.front()->right);
            }
            if (q.front()->left)
            {
                q.push(q.front()->left);
            }
            q.pop();
        }
        return false;
    }
};


void test_solution()
{
    TreeNode* _root = new TreeNode(3);
    TreeNode* leaf1 = new TreeNode(9);
    TreeNode* leaf2 = new TreeNode(20);
    TreeNode* leaf3 = new TreeNode(15);
    TreeNode* leaf4 = new TreeNode(7);
    _root->left = leaf1;
    _root->right = leaf2;
    leaf2->left = leaf3;
    leaf2->right = leaf4;
   // vector<vector<int>> sol = Solution::levelOrder(_root);
    vector<vector<int>> sol = Solution::levelOrderBottom(_root);
    for (int i =0;i<sol.size();i++)
    {
        for(int j=0;j<sol[i].size();j++)
        {
            cout << sol[i][j] ;
        }
        cout << endl;
    }

}
void test_lowestCommonAncestor()
{
    TreeNode* _root = new TreeNode(3);
    TreeNode* _leaf1 = new TreeNode(5);
    TreeNode* _leaf2 = new TreeNode(1);
    TreeNode* _leaf3 = new TreeNode(6);
    TreeNode* _leaf4 = new TreeNode(2);
    TreeNode* _leaf5 = new TreeNode(0);
    TreeNode* _leaf6 = new TreeNode(8);
    TreeNode* _leaf7 = new TreeNode(7);
    TreeNode* _leaf8 = new TreeNode(4);
    _root->left = _leaf1;
    _root->right = _leaf2;
    _leaf1->left = _leaf3;
    _leaf1->right = _leaf4;
    _leaf4->left = _leaf7;
    _leaf4->right = _leaf8;
    _leaf2->left = _leaf5;
    _leaf2->right = _leaf6;
    cout<<Solution::lowestCommonAncestor(_root, _leaf7, _leaf8)->val;

}

int main()
{
    //test_solution();
    test_lowestCommonAncestor();
	return 0;

}