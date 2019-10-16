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

// 给定二叉树返回先序遍历的字符串。
// Input: Binary tree: [1,2,3,4]
// Output: "1(2(4))(3)"
// 使用递归，四种情况，
// 1）左右为空此时就是叶子，直接返回; root
// 2）左为空，此时需要构建空的左括号; root()(right)
// 3) 右为空，可以省略空的右括号; root(left)
// 4) 左右都不为空; root(left)(right)

class Solution {
public:
    string tree2str(TreeNode* t) {
		if (!t) { return ""; }

		string res = to_string(t->val);
		string left = tree2str(t->left), right = tree2str(t->right);
		if (left.empty() && right.empty()) { return res; }
		if (left.empty()) { return res + "()" + "(" + right + ")"; }
		if (right.empty()) { return res + "(" + left + ")"; }
		return res + "(" + left + ")" + "(" + right + ")";
    }
};
