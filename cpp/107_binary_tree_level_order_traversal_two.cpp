/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 和102类似，只是返回的层从底到顶，依然层序遍历，只是存储的时候，每次将新的插入到前面即可

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) { return res; }

		queue<TreeNode *> q{{root}};
        while (!q.empty()) {
			int size = q.size();
			vector<int> level;

			for(int i = 0; i < size; ++i) {
				TreeNode *node = q.front();
				q.pop();
				level.push_back(node->val);
				if (node->left) { q.push(node->left); }
				if (node->right) { q.push(node->right); }
			}
			res.insert(res.begin(), level);
		}
		return res;
    }
};
