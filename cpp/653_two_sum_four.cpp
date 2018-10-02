#include<iostream>
#include<unordered_set>
#include<queue>

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

/*
Given a Binary Search Tree and a target number, 
return true if there exist two elements in the BST such that their sum is equal to the given target.
*/

// 和第一题类似，只不过这次是二分查找树，依然使用target-val 的思路
// 遍历树，将val存入set中，判断set中是否存在target-val即可

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL) return false;
        unordered_set<int> set;
        queue<TreeNode *> q{{root}};
        if (!q.empty()) {
            TreeNode *node = q.front(); q.pop();
            if (set.count(k - node->val)) return true;
            set.insert(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return false;
    }

    bool findTargetVersion2(TreeNode *root, int k) {
        if (!root) return false;
        unordered_set<int> s;
        return judge(root, k, s);
    }

    bool judge(TreeNode *node, int k, unordered_set<int>& s) {
        if (!node) return false;
        if (s.count(k - node->val)) return true;
        s.insert(node->val);
        return judge(node->left, k, s) || judge(node->right, k, s);
    }
};