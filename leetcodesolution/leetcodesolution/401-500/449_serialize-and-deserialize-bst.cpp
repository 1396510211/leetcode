#include <string>
#include <iostream>
#include <queue>
#include <sstream>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root)
	{
		if (root == nullptr) {
			return "#";
		}
		string res;
		res = to_string(root->val);
		res += " ";
		res += serialize(root->left);
		res += " ";
		res += serialize(root->right);
		return res;
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data)
	{
		cout << data;
		stringstream ss(data);
		string s;
		queue<string> theQueue;
		while (ss >> s) {
			theQueue.push(s);
		}
		if (theQueue.empty()) {
			return nullptr;
		}
		return construct(theQueue);
	}
	TreeNode* construct(queue<string>& theQueue)
	{
		string cur = theQueue.front();
		theQueue.pop();
		if (cur == "#") {
			return nullptr;
		}
		TreeNode* root = new TreeNode(stoi(cur));
		root->left = construct(theQueue);
		root->right = construct(theQueue);
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;