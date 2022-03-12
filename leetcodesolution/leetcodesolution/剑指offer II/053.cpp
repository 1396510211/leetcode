// Definition for a binary tree node.

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p)
	{
		TreeNode* res = nullptr;
		TreeNode* cur = root;
		while (cur != nullptr) {
			if (cur->val > p->val) {
				res = cur;
				cur = cur->left;
			}
			else {
				cur = cur->right;
			}
		}
		return res;
	}
};
