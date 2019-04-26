/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 给定二叉树，返回树的最小高度
class Solution {
public:
    int minDepth(TreeNode* root) {
		if (!root) { return 0; }
		queue<TreeNode *> q{{root}};

		vector<vector<int>> res;
		int index = 0;
		while (!q.empty()) {
			int size = q.size();
			if (size < pow(2, index)) { return res.size(); }

			for(int i = 0; i < size; ++i) {	
				TreeNode *node = q.top();
				q.pop();

				level.push_back(node->val);
				if (node->left) { q.push(node->left); }
				if (node->right) { q.push(node->right); }
			}

			res.push(level);
			index++;
		}
        return res.size();
    }
};
