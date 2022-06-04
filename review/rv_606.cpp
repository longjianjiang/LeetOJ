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
class Solution {
public:
    string tree2str(TreeNode* root) {
		if (!root) { return ""; }

		string res = to_string(root->val);
		string left = tree2str(root->left);
		string right = tree2str(root->right);

		if (left.empty() && right.empty()) {
		} else if (left.empty()) {
			res += "()";
			res += "("; res += right; res += ")";
		} else if (right.empty()) {
			res += "("; res += left; res += ")";
			// res += "()";
		} else {
			res += "("; res += left; res += ")";
			res += "("; res += right; res += ")";
		}

		return res;
    }
};
