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
};
*/

// 给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。

// 中序遍历即可；
class Solution {
public:
    TreeNode* KthNode(TreeNode* root, int k) {
		vector<TreeNode *> arr;

		stack<TreeNode *> stk;
		auto pointer = root;
		while (pointer || !stk.empty()) {
			if (pointer) {
				stk.push(pointer);
				pointer = pointer->left;
			} else {
				auto node = stk.top(); stk.pop();
				arr.push_back(node);
				pointer = node->right;
			}
		}

		int idx = k-1;
		if (idx >= arr.size()) { return NULL; }
		return arr[k-1];
	}
};
