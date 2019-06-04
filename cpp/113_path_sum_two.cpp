/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 和112类似，只是这题要求我们返回构成等于sum的路径数组
// 使用递归，增加一个数组路径即可
class Solution {
public:
    void dfs(TreeNode* root, int target, int sum, vector<int> chosen, vector<vector<int>>& res) {
        if (!root) { return; }
        
        sum += root->val;
        chosen.push_back(root->val);
        if (sum == target && !root->left && !root->right) {
            res.push_back(chosen);
            return;
        }
        
        dfs(root->left, target, sum, chosen, res);
        dfs(root->right, target, sum, chosen, res);
	}
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> chosen;
        vector<vector<int>> res;
        dfs(root, sum, 0, chosen, res);
        
        return res;
    }

	vector<vector<int>> pathSumIteration(TreeNode* root, int sum) {
		if (!root) { return {}; }
		stack<TreeNode *> s;
		s.push(root);

		vector<vector<int>> res; vector<int> chosen;
		while(!s.empty()) {
			auto node = s.top(); s.pop();
			chosen.push_back(node->val);
			
			if (!node->left && !node->right && accumulate(chosen.begin(), chosen.end(), 0) == sum) {
				res.push_back(chosen);
				chosen.clear();
			}

			if (node->right) { s.push(node->right); }
			if (node->left) { s.push(node->left); }

		}

		return res;
	}
};
