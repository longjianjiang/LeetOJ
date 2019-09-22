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

// 这里的path是路径组成的path，类似124求和最大的path，递归，比较，返回的时候则返回大的一边。
class Solution {
public:
    int helper(TreeNode* node, int& res) {
        if (!node) { return 0; }

        int left = helper(node->left, res);
        int right = helper(node->right, res);
        left = (node->left && node->val == node->left->val) ? left+1 : 0;
        right = (node->right && node->val == node->right->val) ? right+1 : 0;
        res = max(res, left+right);
        return max(left, right);
    }

    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
};
