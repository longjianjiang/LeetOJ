/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 给定二叉树判断是否是二叉搜索树
// 1. 二叉搜索树的中序遍历是有序的，求出中序遍历结果，如果是有序则验证通过
// 2. 从根开始遍历，左右满足要求，直到叶子节点; ❌ 要求满足的是节点的子树的任意节点满足要求
// 3. 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
       if (!root) { return true; } 

    }
};
