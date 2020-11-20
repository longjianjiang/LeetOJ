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

// 要求返回二叉树最后一行，最左边的节点数值；
// 层序遍历即可；
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (!root) { return -1; }

		vector<vector<int>> rows;
		queue<TreeNode *> q;
		q.push(root);
		int cnt = 1;

		while (!q.empty()) {
			vector<int> nums;
			vector<TreeNode *> nodes;
			while (cnt) {
				TreeNode *front = q.front(); q.pop();
				nodes.push_back(front);
				nums.push_back(front->val);
                --cnt;
			}

			if (!nums.empty()) { rows.push_back(nums); }
			for (auto node: nodes) {
				if (node->left) { q.push(node->left); ++cnt; }
				if (node->right) { q.push(node->right); ++cnt; }
			}
		}

		int nsize = rows.size();
		return rows[nsize-1][0];
    }
};
