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
// 依然是先层序遍历，如果某一层的节点是叶子节点，那么就找到了最小高度
class Solution {
public:
    int minDepth(TreeNode* root) {
		if (!root) { return 0; }
		queue<TreeNode *> q{{root}};

		vector<vector<int>> res;
		int index = 0;
		while (!q.empty()) {
			int size = q.size();
			vector<int> level;

			for(int i = 0; i < size; ++i) {	
				TreeNode *node = q.front();
				q.pop();

				if (!node->left && !node->right) { return res.size()+1; }
				level.push_back(node->val);
				if (node->left) { q.push(node->left); }
				if (node->right) { q.push(node->right); }
			}

			res.push_back(level);
		}
        return res.size();
    }
};
