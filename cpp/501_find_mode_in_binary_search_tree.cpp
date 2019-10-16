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

// 给定bst，返回出现次数最多的数字集合。
// 1> 遍历tree，用map记录key对应的次数，同时记录最大次数，最后遍历map，返回结果；
// 2> 不用map记录，中序遍历的时候进行记录大小关系；
class Solution {
public:
	void helper(TreeNode* node, TreeNode*& prev /* need reference */, int& cnt, int& max, vector<int>& res) {
		if (!node) { return; }
		helper(node->left, prev, cnt, max, res);
		if (prev) {
			cnt = (node->val == prev->val) ? cnt+1 : 1;	
		}
		if (cnt >= max) {
			if (cnt > max) { res.clear(); }
			res.push_back(node->val);
			max = cnt;
		}
		prev = node;
		helper(node->right, prev, cnt, max, res);
	}

    vector<int> findMode(TreeNode* root) {
		vector<int> res;
		int cnt = 1, max = 0;
		TreeNode *prev = NULL;
		helper(root, prev, cnt, max, res);
		return res;
    }
};
