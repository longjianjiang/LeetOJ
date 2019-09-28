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

// 给定一个bst，给定k，返回第k小的元素
// 1> inOrder 遍历；
// 2> dfs，计数，每次从left开始，其次是right，当等于k就找到了这个数字。
class Solution {
public:
	void dfs(TreeNode* node, int& count, int k, int& res) {
		if (!node) { return; }
		
		dfs(node->left, count, k, res);
		++count;
		if (count == k) {
			res = node->val;
			return;
		}
		dfs(node->right, count, k, res);
	}

    int kthSmallest(TreeNode* root, int k) {
		int cnt = 0;
		int res = 0;
		dfs(root, cnt, k, res);
		return res;
    }
};

