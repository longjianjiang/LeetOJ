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

// 返回二叉树所有子树和中出现次数最多的值；

// 1> 遍历每个节点，求和，返回结果；这样会导致重复计算；
// 2> 后序遍历，同时使用map记录下子树的和；
// 获取所有子树和后，使用map找到出现的最大次数，返回最大次数的数字；
class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
		vector<int> sums;
		unordered_map<TreeNode *, int> um;

		getTreeSum(root, sums, um);

		unordered_map<int, int> dict;
		int times = 0;
		for (auto sum: sums) {
			dict[sum] += 1;
			if (dict[sum] > times) { times = dict[sum]; }
		}
		vector<int> res;
		for (auto it = dict.begin(); it != dict.end(); ++it) {
			if (times == it->second) { res.push_back(it->first); }
		}
	
		return res;
    }

	void getTreeSum(TreeNode *root, vector<int>& sums, unordered_map<TreeNode *, int>& um) {
		if (!root) { return; }
		getTreeSum(root->left, sums, um);
		getTreeSum(root->right, sums, um);

		int leftSum = 0, rightSum = 0;
		if (root->left) { leftSum = um[root->left]; }
		if (root->right) { rightSum = um[root->right]; }

		int sum = root->val + leftSum + rightSum;
		sums.push_back(sum);
		um[root] = sum;
	}
};
