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

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

// 判断二叉树B是不是A的子树(节点也需要相同)，空树不算子树；
// 1> 树一般都需要递归，首先判断首节点是否相等，相等则helper（进行结构的比对），否则递归的去判断parent的左右子树即可；
// 	  递归不一定只有一个方法，需要根据条件去判断；
class Solution {
public:
    bool HasSubtree(TreeNode* parent, TreeNode* child) {
		if (!parent || !child) { return false; }

		bool res = false;
		if (parent->val == child->val) {
			res = helper(parent, child);
		}
		if (!res) {
			return HasSubtree(parent->left, child) ||
				HasSubtree(parent->right, child);
		}
		return true;
	}

	bool helper(TreeNode *parent, TreeNode *child) {
		if (!child) { return true; }
		if (!parent) { return false; }

		if (parent->val == child->val) {
			return helper(parent->left, child->left) &&
				helper(parent->right, child->right);
		} else {
			return false;
		}
	}
};
