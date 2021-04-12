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

// 判断二叉树是否为二叉搜索树。
// 迭代的方式遍历，每次看当前节点是否小于上一个节点，因为中序遍历的结果一定是有序的。
bool isValidBSTIteration(TreeNode *root) {
	if (!root) { return true; }

	stack<TreeNode *> s;
	auto node = root;
	vector<TreeNode *> v;

	while (!s.empty() || node) {
		while (node) {
			s.push(node);
			node = node->left;
		}

		auto top = s.top(); s.pop();
		if (v.empty()) {
			v.push_back(top);
		} else {
			auto tmp = v.back();
			if (top->val <= tmp->val) { return false; }
			v.push_back(top);
		}

		node = top->right;
	}

	return true;
}
