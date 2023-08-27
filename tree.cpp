
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历） 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) { return res; }
		queue<TreeNode *> q;
		q.push(root);
		bool flag = true;
		while (!q.empty()) {
			vector<TreeNode *> level;
            vector<int> tmp;
			while (!q.empty()) {
				level.push_back(q.front());
				q.pop();
			}
			for (auto node : level) {
                tmp.push_back(node->val);
				if (node->left) { q.push(node->left); }
				if (node->right) { q.push(node->right); }
			}

			if (!flag) {
				reverse(tmp.begin(), tmp.end());
			}
			flag = !flag;
			res.push_back(tmp);
		}
		return res;
    }
};
