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

// 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

// 层序遍历，增加一个标记位是否进行reverse即可；
class Solution {
public:
    vector<vector<int> > Print(TreeNode* root) {
		if (!root) { return {}; }
		vector<vector<int>> res;

		queue<TreeNode *> q;
		q.push(root);
		int cnt = q.size();
		bool flag = true;
		while (!q.empty()) {
			vector<int> tmp;
			for (int i = 0; i < cnt; ++i) {
				auto node = q.front(); q.pop();
				tmp.push_back(node->val);
				if (node->left) { q.push(node->left); }
				if (node->right) { q.push(node->right); }
			}
			if (flag) {
				res.push_back(tmp);
			} else {
				reverse(tmp.begin(), tmp.end());
				res.push_back(tmp);
			}
			flag = !flag;
			cnt = q.size();
		}

		return res;
    }
};
