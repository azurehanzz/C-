#include <iostream>
#include <vector>
#include <queue>
#include <climits> 
using namespace std;
const int NULLvalue = INT_MIN;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    static TreeNode* TreeNode_struct_by_vector(vector<int>x)
    {
        if (x.size() > 0)
        {
            TreeNode* root = new TreeNode(x[0]);
            TreeNode* parent = root;
            queue<TreeNode*> parent_node;
            parent_node.push(parent);
            int child_idx = 1;
            int parent_idx = 0;
            while (child_idx < x.size())
            {
                if (x[child_idx] != NULLvalue)
                {
                    TreeNode* child = new TreeNode(x[child_idx]);
                    parent_node.push(child);
                    if (child_idx == 2 * parent_idx + 1)
                    {
                        parent->left = child;
                        child_idx++;
                    }
                    else if (child_idx == 2 * parent_idx + 2)
                    {
                        parent->right = child;
                        parent_idx++;
                        child_idx++;
                        parent_node.pop();
                        parent = parent_node.front();
                    }
                }
                else
                {
                    if (child_idx == 2 * parent_idx + 1)
                    {
                        child_idx++;
                    }
                    else if (child_idx == 2 * parent_idx + 2)
                    {
                        parent_idx++;
                        child_idx++;
                        if (x[parent_idx] != NULLvalue)
                        {
                            parent_node.pop();
                            parent = parent_node.front();
                        }
                    }
                }
            }
            return root;
        }
        else
        {
            return nullptr;
        }
    }
};

void inorder(TreeNode* root)
{
    if (root->left)
    {
        inorder(root->left);
    }
    cout << root->val;
    if (root->right)
    {
        inorder(root->right);
    }
    return;
}
class Solution {
public:
    static void _Convert(TreeNode* cur,TreeNode*pre)
    {
        if (cur == nullptr)
            return;
        _Convert(cur->left, pre);
        
        
   
        return;
    };
   static  TreeNode* Convert(TreeNode* pRootOfTree) {
       if (pRootOfTree == nullptr)
       {
           return nullptr;
       }
        _Convert(pRootOfTree,nullptr);
     
       while (pRootOfTree ->left)
       {
           pRootOfTree = pRootOfTree->left;
       }
       return pRootOfTree;
    };
   static  TreeNode* leeConvert(TreeNode* pRootOfTree)
   {
       if (pRootOfTree == nullptr) return nullptr;
       TreeNode* pre = nullptr;

       convertHelper(pRootOfTree, pre);

       TreeNode* res = pRootOfTree;
       while (res->left)
           res = res->left;
       return res;


   }


   static void convertHelper(TreeNode* cur, TreeNode*& pre)
   {
       if (cur == nullptr) return;

       convertHelper(cur->left, pre);

       cur->left = pre;
       if (pre) pre->right = cur;
       pre = cur;

       convertHelper(cur->right, pre);
   }
};

void print_root2list(TreeNode* root)
{
    while (root->left)
    {
        root = root->left;
    }
    while (root)
    {
        cout << root->val;
        cout << "->";
        root = root->right;
    }
    cout << "end";
}



void Test_Convert()
{
    vector<int> root;
    int arr[] =
    { 10,6,14,4,8,12,16 };
    for (auto e : arr)
    {
        root.push_back(e);
    }
    TreeNode* _root = TreeNode::TreeNode_struct_by_vector(root);
    inorder(_root);
    cout << endl;
    Solution::leeConvert(_root);
    print_root2list(_root);
}
int main()
{

    Test_Convert();
    return 0;

}