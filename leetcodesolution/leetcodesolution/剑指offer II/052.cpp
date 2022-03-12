#include "../pch.h"

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	TreeNode* increasingBST(TreeNode* root)
	{
		Intraversal(root);
		if (res.empty()) {
			return nullptr;
		}
		TreeNode* theNewTree = new TreeNode(res[0]);
		TreeNode* cur = theNewTree;
		for (size_t i = 1; i < res.size(); i++) {
			TreeNode* node = new TreeNode(res[i]);
			cur->right = node;
			cur = node;
		}
		return theNewTree;
	}
	void Intraversal(TreeNode* root)
	{
		if (root == nullptr) {
			return;
		}
		if (root->left) {
			Intraversal(root->left);
		}
		res.push_back(root->val);
		if (root->right) {
			Intraversal(root->right);
		}
	}
	vector<int> res;
};