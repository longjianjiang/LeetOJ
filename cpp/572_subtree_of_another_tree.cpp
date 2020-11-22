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

// 判断二叉树是否是子树，自己也是自己的子树；
// 递归判断即可；
// 开始使用helper的思路有问题，问题在于把判断是否是相同二叉树和递归判断子树混在了一起，导致了逻辑的错误。
// 所以需要进行逻辑的拆分。isSubTree判断是否是子树，isSameTree判断是否是同一课树；
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
		if (isSameTree(s, t)) {
			return true;
		} else {
			bool one = s->left ? isSubtree(s->left, t) : false;
			bool two = s->right ? isSubtree(s->right, t) : false;

			return one || two;
		}
    }

	bool isSameTree(TreeNode *s, TreeNode *t) {
		if (!s && !t) { return true; }
		if (!s || !t) { return false; }

		if (s->val == t->val) {
			return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
		} else {
			return false;
		}
	}

	bool helper(TreeNode *s, TreeNode *t) {

		if (s->val == t->val) {
			return helper(s->left, t->left) && helper(s->right, t->right);
		} else {
			return helper(s->left, t) || helper(s->right, t);
		}
	}
};
