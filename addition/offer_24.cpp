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

// 输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
// 1> dfs;
// 2> 迭代，中序遍历；
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		vector<int> chosen;
		vector<vector<int>> res;
		dfs(root, expectNumber, 0, chosen, res);

		return res;
    }

	void dfs(TreeNode *node, int target, int sum, vector<int> chosen, vector<vector<int>>& res) {
		if (!node) { return; }

		sum += node->val;
		chosen.push_back(node->val);
		if ((sum == target) && !node->left && !node->right) {
			res.push_back(chosen);
			return;
		}

		dfs(node->left, target, sum, chosen, res);
		dfs(node->right, target, sum, chosen, res);
	}

	vector<vector<int>> findPath(TreeNode *root, int target) {
	}
};
