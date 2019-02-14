/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <vector>

using namespace std;

// 给定二叉树的前序遍历和中序遍历，让我们构建出二叉树返回
// 首先根据先序遍历确定根节点，然后构建左右子数的先序数组和中序数组，递归的用其构建左右子树

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.size() == 0) return NULL;
        int treeSize = pre.size();
        vector<int> leftPreorder, leftInorder, rightPreorder, rightInorder;

        TreeNode *head = new TreeNode(pre[0]);
        int rootNodeIdxAtInorder = 0;
        for (int i = 0; i < treeSize; i++) {
             if (vin[i] == pre[0]) {
                rootNodeIdxAtInorder = i;
                break;
            }
        }

        for (int i = 0; i < rootNodeIdxAtInorder; ++i) {
            leftInorder.push_back(vin[i]);
            leftPreorder.push_back(pre[i+1]);
        }
        for (int i = rootNodeIdxAtInorder+1; i < treeSize; ++i) {
            rightInorder.push_back(vin[i]);
            rightPreorder.push_back(pre[i]);
        }

        head->left = reConstructBinaryTree(leftPreorder, leftInorder);
        head->right = reConstructBinaryTree(rightPreorder, rightInorder);

        return head;
    }
};