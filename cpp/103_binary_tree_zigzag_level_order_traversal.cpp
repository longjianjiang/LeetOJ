/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 和102 类似，返回层序遍历的二维数组，不过这次返回的是所谓的zigzag模式

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) { return res; }

		queue<TreeNode *> q{{root}};
		bool is_reverse = false;
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

			if (!is_reverse) {
				res.push_back(level);
			} else {
				reverse(level.begin(), level.end());
				res.push_back(level);
			}
			is_reverse = !is_reverse;
		}
		return res; 
    }
};
