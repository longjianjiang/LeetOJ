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

/*
 * ref: https://leetcode.cn/problems/count-good-nodes-in-binary-tree/?envType=study-plan-v2&envId=leetcode-75
 * 
 */

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

class Solution {
public:
	int goodNodes(TreeNode* root) {
        if (!root) { return 0; }
        int res = 1;
        dfs(root->left, root->val, res);
        dfs(root->right, root->val, res);

        return res;
    }

    void dfs(TreeNode *root, int maxVal, int& res) {
        if (!root) { return; }

        if (root->val >= maxVal) {
            ++res;
            maxVal = root->val;
        }
        dfs(root->left, maxVal, res);
        dfs(root->right, maxVal, res);
    }
};
