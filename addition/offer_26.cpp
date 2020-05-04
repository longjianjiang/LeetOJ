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

// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

// 1> 中序遍历，改变指向；
class Solution {
public:
    TreeNode* Convert(TreeNode* root) {
		if (!root) { return NULL; }

		TreeNode *pointer = root, *head = NULL, *prev = NULL;
		stack<TreeNode *> stk;
		while (!stk.empty() || pointer) {
			while (pointer) {
				stk.push(pointer);
				pointer = pointer->left;
			}
			pointer = stk.top();
			if (!head) { head = pointer; }

			if (prev) { prev->right = pointer; }
			pointer->left = prev;
			prev = pointer; 

			stk.pop();
			pointer = pointer->right;
		}

		return head;
    }
};
