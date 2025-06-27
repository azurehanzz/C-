#include <iostream>
#include <string>
#include <vector>

using namespace std;
//二叉搜索树与双向链表


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	static TreeNode* Convert(TreeNode* pRootOfTree) {
		if(pRootOfTree)
		{
			_Convert(pRootOfTree);
			TreeNode* reval = pRootOfTree;
			while (reval->left)
			{
				reval = reval->left;
			}
			return reval;
		}
		return nullptr;


	}
	static void _Convert(TreeNode* pRootOfTree)
	{
		TreeNode* left = left_sort(pRootOfTree);
		TreeNode* right = right_sort(pRootOfTree);
		if (left)
		{
			_Convert(left);
		}
		if (right)
		{
			_Convert(right);
		}
		return ;
	}
	static::TreeNode* left_sort(TreeNode* root) {
		TreeNode* parent = root;
		TreeNode* child = root->left;
		if (child == nullptr||root->left->right == root)
		{
			return nullptr;
		}
		while (child->right)
		{
			parent = child;
			child = child->right;
		}
		if (parent == root)
		{
			child->right = parent;
			if (child->left)
			{
				return child;
			}
			return nullptr;
		}
		parent->right = child->left;
		child->left = root->left;
		if (root->left->right == nullptr)
		{
			root->left->right = child;
		}
		child->right = root; 
		root->left = child;
		return child->left;
	}
	static::TreeNode* right_sort(TreeNode* root) {
		TreeNode* parent = root;
		TreeNode* child = root->right;
		if (child == nullptr||root->right->left == root)
		{
			return nullptr;
		}
		while (child->left)
		{
			parent = child;
			child = child->left;
		}
		if (parent == root)
		{
			child->left = parent;
			if (child->right)
			{
				return child;
			}
			return nullptr;
		}
		parent->left = child->right;
		child->right = root->right;
		if (root->right->left==nullptr)
		{
			root->right->left = child;
		}
		child->left = root;
		root->right = child;
		return child->right;
	}
};
void Test_Convert()
{
	TreeNode* root = new TreeNode(10);
	TreeNode* leaf1 = new TreeNode(6);
	TreeNode* leaf2 = new TreeNode(14);
	TreeNode* leaf3 = new TreeNode(4);
	TreeNode* leaf4 = new TreeNode(8);
	TreeNode* leaf5 = new TreeNode(12);
	TreeNode* leaf6 = new TreeNode(16);
	root->left = leaf1;
	root->right = leaf2;
	leaf1->left = leaf3;
	leaf1->right = leaf4;
	leaf2->left = leaf5;
	leaf2->right = leaf6;
	Solution::Convert(root);

}
namespace buildTree
{
	class Solution {
	public:
		static TreeNode* buildTree(vector<int>& preorder , vector<int>& inorder) {
			int root_idx = 0;
			TreeNode* root = new TreeNode(preorder[root_idx]);
			if (preorder[root_idx] == inorder[root_idx])
			{
				root_idx++;
				if (root_idx < preorder.size())
				{
					TreeNode* root_right = new TreeNode(preorder[root_idx]);
					root->right = root_right;
					root = root->right;
				}
			}
			else
			{

			}
		}
	};
}
void Test_bulidTree()
{
	vector<int> pre;
	pre.push_back(3);
	pre.push_back(9);
	pre.push_back(20);
	pre.push_back(15);
	pre.push_back(7);
	vector<int> in;
	in.push_back(9);
	in.push_back(3);
	in.push_back(15);
	in.push_back(20);
	in.push_back(7);
	buildTree::Solution::buildTree(pre,in);
}
int main()
{
	

	return 0;
}