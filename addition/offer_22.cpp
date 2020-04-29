#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// 从上往下打印出二叉树的每个节点，同层节点从左至右打印。

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

// 使用队列，层序遍历即可；
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> res;
		if (!root) { return res; }

		queue<TreeNode *> q; q.push(root);
		while (!q.empty()) {
			auto node = q.front(); q.pop();
			res.push_back(node->val);
			if (node->left) { q.push(node->left); }
			if (node->right) { q.push(node->right); }
		}
		return res;
    }
};
