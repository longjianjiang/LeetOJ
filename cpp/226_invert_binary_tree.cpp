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

// 给定满二叉树，翻转，每棵子树都要进行翻转。
// 递归即可，从根开始交换指向，递归左右子树。
class Solution {
public:
    void helper(TreeNode* node) {
        if (!node) { return; }
        if (!node->left && !node->right) { return; }

        auto tmp = node->right;
        node->right = node->left;
        node->left = tmp;
        helper(node->left);
        helper(node->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        return root;
    }
};
