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

// 输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

// 1> 层序遍历即可；
class Solution {
public:
    int TreeDepth(TreeNode* pRoot) {
		if (!pRoot) { return 0; }
		int res = 0;
		queue<TreeNode *> q;
		q.push(pRoot);
		
		int cnt = 1;
		while (!q.empty()) {
			++res;

			int tmp = 0;
			for (int i = 0; i < cnt; ++i) {
				auto node = q.front(); q.pop();
				if (node->left) { q.push(node->left); ++tmp; }
				if (node->right) { q.push(node->right); ++tmp; }
			}
			cnt = tmp;
		}
		return res;
	}
};
