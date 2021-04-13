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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 后序遍历；左右中；
void post_order(TreeNode *root) {
	if (!root) { return; }

	stack<TreeNode *> s;
	auto node = root;
	TreeNode *prev = NULL;

	while (!s.empty() || node) {
		while (node) {
			s.push(node);
			node = node->left;
		}
		if (!s.empty()) {
			auto top = s.top(); s.pop();
			if (!top->right || top->right == prev) {
				prev = node;
				cout << top->val << endl;
				node = NULL;
			} else {
				s.push(top);
				node = top->right;
			}
		}
	}
}
