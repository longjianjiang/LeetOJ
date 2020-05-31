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

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/

// 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
class Solution {
public:
	vector<vector<int> > Print(TreeNode* root) {
		if (!root) { return {}; }
		vector<vector<int>> res;

		queue<TreeNode *> q;
		q.push(root);
		int cnt = q.size();
		while (!q.empty()) {
			vector<int> tmp;
			for (int i = 0; i < cnt; ++i) {
				auto node = q.front(); q.pop();
				tmp.push_back(node->val);
				if (node->left) { q.push(node->left); }
				if (node->right) { q.push(node->right); }
			}
			res.push_back(tmp);
			cnt = q.size();
		}

		return res;
	}

};
