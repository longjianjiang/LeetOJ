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

	// 使用迭代的方式
	// 中序遍历获取每条从根到叶子的路径，有一个需要注意的地方在于移除节点，需要额外增加一个指针来判断右节点是否添加过，否则需要进行移除
	vector<vector<int>> pathSumIteration(TreeNode* root, int sum) {
		if (!root) { return {}; }

		vector<vector<int>> res;
		vector<TreeNode *> s;
		TreeNode *pointer = root, *pre = NULL;
		int total = 0;

		while(!s.empty() || pointer) {
			while(pointer) {
				s.push_back(pointer);
				total += pointer->val;
				pointer = pointer->left;
			}

			pointer = s.back();
			if (!pointer->left && !pointer->right && total == sum) {
				vector<int> v;
				for (auto n : s) {
					v.push_back(n->val);
				}
				res.push_back(v);
			}

			if (pointer->right && pointer->right != pre) { // remove right child's parent node
				pointer = pointer->right;
			} else {
				total -= pointer->val;
				pre = pointer;
				s.pop_back();
				pointer = NULL;
			}
		}

		return res;
	}
};
