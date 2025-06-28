#include <iostream>
#include <vector>
#include <queue>
#include <climits> 
using namespace std;
const int NULLvalue = INT_MIN;
 struct TreeNode {
    int val;
    TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    static TreeNode* TreeNode_struct_by_vector(vector<int>x)
    {
        if(x.size()>0)
        {
            TreeNode* root = new TreeNode(x[0]);
            TreeNode* parent = root;
            queue<TreeNode*> parent_node;
            parent_node.push(parent);
            int child_idx = 1;
            int parent_idx = 0;
            while (child_idx < x.size())
            {
                if(x[child_idx]!= NULLvalue)
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
                        if(x[parent_idx]!=NULLvalue)
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

 class Solution {
 public:
     static TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         //如果一个在左一个在右,那么此节点即为最小公共祖先
         //如果一个节点是根,那么此节点也为最小公共祖先
         //如果穿的根是空值,返回空值
         //采用递归的思想来进行解题
         if (root == nullptr)
         {
             return nullptr;
         }
         if (root == p || root == q)
         {
             return root;
         }
         bool pisleft = find(root->left, p);
         bool pisright = !pisleft;
         bool qisleft = find(root->left, q);
         bool qisright = !qisleft;
         if ((pisleft && qisright) || (pisright && qisleft))
             return root;
         if (pisleft && qisleft)
             return lowestCommonAncestor(root->left, p, q);
         if (pisright && qisright)
             return lowestCommonAncestor(root->right, p, q);



     }
     static bool find(TreeNode* root, TreeNode* node)
     {
         if (root)
             return root == node || find(root->left, node) || find(root->right, node);
         else
             return false;
     }
 };

 void test_lowestCommonAncestor()
 {
     vector<int> root;
     int arr[] = { 3,5,1,6,2,0,8,NULLvalue,NULLvalue,7,4 };
     for (auto e : arr)
     {
         root.push_back(e);
     }
     TreeNode* _root = TreeNode::TreeNode_struct_by_vector(root);
     TreeNode*result = Solution::lowestCommonAncestor(_root, _root->left->left, _root->left->right);
     cout << result->val;
 }


 namespace Convert
 {
     class Solution {
     public:
         static TreeNode* _Convert(TreeNode* parent, TreeNode* child)
         {
             if (child->left)
             {
                 _Convert(child, child->left);
             }
             child->right = parent;
             if (child->right)
             {
                 _Convert(child, child->right);
             }
             child->left = parent;
             return child;
         }
         TreeNode* Convert(TreeNode* pRootOfTree) {

         };
     };
 };

 void Test_Convert()
 {
     vector<int> root;
     int arr[] = { 3,5,1,6,2,0,8,NULLvalue,NULLvalue,7,4 };
     for (auto e : arr)
     {
         root.push_back(e);
     }
     TreeNode* _root = TreeNode::TreeNode_struct_by_vector(root);
     Convert::Solution::_Convert(_root, _root);
 }
int main()
{

   // test_lowestCommonAncestor();
    Test_Convert();
	return 0;

}