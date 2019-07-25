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

// 给定二叉树，返回右侧的节点数组。
// 层序遍历，将每层的最右节点放入数组即可。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) { return res; }

        queue<TreeNode *> q;
        q.push(root);
        int cnt = 1;

        while (!q.empty()) {
            int sum = 0;
            for (int i = 0; i < cnt; ++i) {
                TreeNode *node = q.front(); q.pop();
                if (i == 0) { res.push_back(node->val); }

                if (node->right) { q.push(node->right); sum++; }
                if (node->left) { q.push(node->left); sum++; }
            }
            cnt = sum;
        }

        return res;
    }
};
