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

// 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
// 所谓平衡二叉树，就是所有节点的子树高度相差不超过1；

// 1> 递归；算出左右子树的高度，判断差；(节点会被重复调用)
// 2> 后序遍历, 从底左右高度，依次到根节点；
class Solution {
public:
	int helper(TreeNode *node) {
		if (!node) { return 0; }
		if (!node->left && !node->right) { return 1; }
		return max(helper(node->left)+1, helper(node->right)+1);
	}

    bool IsBalanced_Solution(TreeNode* pRoot) {
		if (!pRoot) { return true; }

		int leftCnt = helper(pRoot->left);
		int rightCnt = helper(pRoot->right);

		return abs(leftCnt-rightCnt) <= 1 &&
			IsBalanced_Solution(pRoot->left) &&
			IsBalanced_Solution(pRoot->right);
    }

	bool helper(TreeNode *node, int& depth) {
		if (!node) { depth = 0; return true; }

		int left = 0, right = 0;
		if (helper(node->left, left) && helper(node->right, right)) {
			int diff = abs(left-right);

			if (diff <= 1) {
				depth = max(left+1, right+1);
				return true;
			}
		}

		return false;
	}

	bool isBalancedTree(TreeNode *root) {
		int depth = 0;
		return helper(root, depth);
	}
};
