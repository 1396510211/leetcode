#include <queue>
using namespace std;
//Definition for a binary tree node.

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
	bool isCousins(TreeNode* root, int x, int y)
	{
		if (root == nullptr) {
			return false;
		}
		queue<pair<TreeNode*, TreeNode*>> theQueue;
		theQueue.push({ root,nullptr });
		while (!theQueue.empty()) {
			int size = theQueue.size();
			bool b1 = false;
			bool b2 = false;
			TreeNode* p1 = nullptr;
			TreeNode* p2 = nullptr;
			for (int i = 0; i < size; i++) {
				// 不能使用引用 避免提前释放内存
				auto [cur, parent] = theQueue.front();
				if (cur->val == x) {
					b1 = true;
					p1 = parent;
				}
				if (cur->val == y) {
					b2 = true;
					p2 = parent;
				}
				theQueue.pop();
				if (cur->left)
					theQueue.push({ cur->left, cur });
				if (cur->right)
					theQueue.push({ cur->right ,cur });
			}
			if (b1 && b2) {
				return p1 != p2;
			}
		}
		return false;
	}
};