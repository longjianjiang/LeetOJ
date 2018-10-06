#include<iostream>
#include<vector>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


// 给定升序数组，构建一个二分查找树
// 构建二分查找树首先找到根节点，也就是数组的中点，此时数组剩下左右两段，对这两段递归的创建子树

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return getBST(nums, 0, nums.size()-1);
    }
private:
    TreeNode* getBST(vector<int>& nums, int left, int right) {
        if (left > right) return NULL;

        auto mid = (left + right) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = getBST(nums, left, mid-1);
        node->right = getBST(nums, mid+1, right);

        return node;
    }
};


