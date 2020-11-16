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

// 给定一个数组，找到最大的作为树的根，左边数组作为左子树，右边数组作为右子树。依次类推。
// 递归即可
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return helper(nums);
    }

	TreeNode* helper(vector<int> nums) {
		if (nums.empty()) { return NULL; }
        
        int nsize = nums.size();
		int maxNum = INT_MIN;
		int idx = 0;
		for (int i = idx; i < nsize; ++i) {
			if (nums[i] > maxNum) { 
				maxNum = nums[i]; 
				idx = i;
			}
		}
		vector<int> left(nums.begin(), nums.begin()+idx);
		vector<int> right(nums.begin()+idx+1, nums.end());

		TreeNode *node = new TreeNode(maxNum);
		node->left = helper(left);
		node->right = helper(right);

		return node;
	}};
