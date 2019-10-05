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

// 给定先序和后序，构造一颗符合要求的二叉树。
/*
	2		2
   /		 \ 
  5			  5	
  pre : [2, 5]
  post: [5, 2]
*/
// 返回一种情况即可，这里返回的是左子树的情况。
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
		if (pre.empty() && post.empty()) { return NULL; }
		if (pre.size() == 1 && post.size() == 1) { return new TreeNode(pre[0]); }

		auto root = new TreeNode(pre[0]);
		vector<int> left_pre, left_post, right_pre, right_post;
		int left_root = pre[1], left_len = 0;
		for (int i = 0; i < post.size(); ++i) {
			if (post[i] == left_root) { left_len = i+1; break; }
		}
		for (int i = 0; i < left_len; ++i) {
			left_pre.push_back(pre[i+1]);
			left_post.push_back(post[i]);
		}
		for (int i = left_len; i < post.size()-1; ++i) {
			right_pre.push_back(pre[i+1]);
			right_post.push_back(post[i]);
		}

		root->left = constructFromPrePost(left_pre, left_post);
		root->right = constructFromPrePost(right_pre, right_post);

		return root;
    }
};
