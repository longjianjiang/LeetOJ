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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 给定一个有序整数数组，元素各不相同且按升序排列，编写一个算法，创建一棵高度最小的二叉搜索树。
// 1> 每次取中点作为根，左右两边作为左右子树。递归。
class Solution {
public:
	TreeNode* createTree(vector<int>& nums) {
		if (nums.empty()) { return NULL; }

		int left = 0, right = nums.size()-1;
		int mid = left + (right - left) / 2;
		int num = nums[mid];
		vector<int> leftPart;
		vector<int> rightPart;

        for (int i = left; i < mid; ++i) { leftPart.push_back(nums[i]); }
        for (int i = mid+1; i <= right; ++i) { rightPart.push_back(nums[i]); }
        
		auto node = new TreeNode(num);
		node->left = createTree(leftPart);
		node->right = createTree(rightPart);
	
		return node;
	}

    TreeNode* sortedArrayToBST(vector<int>& nums) {
		return createTree(nums);
    }
};
