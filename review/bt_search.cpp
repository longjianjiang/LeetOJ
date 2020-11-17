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

void print_preorder(TreeNode *node) {
	if (!node) { return; }

	stack<TreeNode *> stk;
	stk.push(node);

	while (!stk.empty()) {
		auto tmp = stk.top(); stk.pop();
		cout << tmp->val << " ";
		if (tmp->right) {
			stk.push(tmp->right);
		}
		if (tmp->left) {
			stk.push(tmp->left);
		}
	}
}

void print_inorder(TreeNode *node) {
	if (!node) { return; }

	stack<TreeNode *> stk;
	auto pointer = node;

	while (pointer || !stk.empty()) {
		if (pointer) {
			stk.push(pointer);
			pointer = pointer->left;
		} else {
			auto top = stk.top(); stk.pop();
			cout << top->val << " ";
			pointer = top->right;
		}
	}
}

void print_postorder(TreeNode *node) {
	if (!node) { return; }

	stack<TreeNode *> stk;
	auto pointer = node;
	TreeNode *prev = NULL;

	while (pointer || !stk.empty()) {
		while (pointer) {
			stk.push(pointer);
			pointer = pointer->left;
		}
		if (!stk.empty()) {
			pointer = stk.top(); stk.pop();
			if (!pointer->right || pointer->right == prev) {
				prev = pointer;
				cout << pointer->val << " ";
				pointer = NULL;
			} else {
				stk.push(pointer);
				pointer = pointer->right;
			}
		}
	}
}

void print_preorder_recursive(TreeNode *node) {
	if (!node) { return; }
	cout << node->val << " ";
	print_preorder_recursive(node->left);
	print_preorder_recursive(node->right);
}

void print_inorder_recursive(TreeNode *node) {
	if (!node) { return; }
	print_inorder_recursive(node->left);	
	cout << node->val << " ";
	print_inorder_recursive(node->right);
}

void print_postorder_recursive(TreeNode *node) {
	if (!node) { return; }
	print_postorder_recursive(node->left);
	print_postorder_recursive(node->right);
	cout << node->val << " ";
}

void unit_test() {
	auto seven = new TreeNode(7);
	auto eight = new TreeNode(8);
	auto six = new TreeNode(6);
	auto four = new TreeNode(4);

	auto five = new TreeNode(5); five->left = seven; five->right = eight;
	auto two = new TreeNode(2); two->left = four; two->right = five;
	auto three = new TreeNode(3); three->right = six;
	auto one = new TreeNode(1); one->left = two; one->right = three;

	print_preorder(one);
	cout << "\n";
	print_preorder_recursive(one);
	cout << "\n";

	print_inorder(one);
	cout << "\n";
	print_inorder_recursive(one);
	cout << "\n";

	print_postorder(one);
	cout << "\n";
	print_postorder_recursive(one);
	cout << "\n";
}

int main() {
	unit_test();
	return 0;
}
