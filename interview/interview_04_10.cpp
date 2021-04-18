#include <iostream> #include <vector>
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
// 检查t2是否是t1的子树；
// 递归判断即可。
class Solution {
public:
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
		if (!t1 && !t2) { return true; }
        if (!t1) { return false; }
        if (!t2) { return true; }

        if (t1->val == t2->val) {
            return checkSubTree(t1->left, t2->left) && checkSubTree(t1->right, t2->right);
        } else {
            return checkSubTree(t1->left, t2) || checkSubTree(t1->right, t2);
        }
    }
};
