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

// 求二叉树path最大的和
// 开始想法是递归，分了很多种情况，根的大小，结果依然有case过不了。
// 后来参考别人的解法，发现是自己递归的不够彻底，首先加入一个比较的机制，因为存储一个节点就是最大path的情况。一个节点其实也是一个树，只是左右为空而已。常规操作就是先求左边最大的，再求右边最大的，此时最大的就是根+左+右。因为有比较的存在也就不需要之前解法中的很多判断了。
class Solution {
    int maxSum = INT_MIN;
public:
    int dfs(TreeNode* root) {
        if (!root) { return 0; }

        int left = max(dfs(root->left), 0);
        int right = max(dfs(root->right), 0);

        maxSum = max(maxSum, root->val+left+right);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        return max(dfs(root), maxSum);
    }
};
