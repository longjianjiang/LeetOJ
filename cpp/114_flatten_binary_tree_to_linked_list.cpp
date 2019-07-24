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

// 先序遍历的方式来遍历，拼接链表即可。
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) { return; }

        stack<TreeNode *> s;
        if (root->right) { s.push(root->right); }
        if (root->left) { s.push(root->left); }

        TreeNode *node = root; node->left = NULL;
        while (!s.empty()) {
            TreeNode *top = s.top(); s.pop();
            node->right = top;

            if (top->right) { s.push(top->right); }
            if (top->left) { s.push(top->left); top->left = NULL; }

            node = top;
        }
    }
};


