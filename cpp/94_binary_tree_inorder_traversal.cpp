/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 迭代的方式中序遍历二叉树
// 利用递归的思路即可，使用栈来保存节点即可
// 还有一种不使用栈的迭代方式，利用右子树为空的节点来存储中序遍历的后继节点
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
		if (!root) { return {}; }

		stack<TreeNode *> s;
		vector<int> res;
		auto pointer = root;
		while (pointer || !s.empty()) {
			while (pointer) {
				s.push(pointer);
				pointer = pointer->left;
			}

			auto node = s.top();
			s.pop();
			res.push_back(node->val);
			pointer = node->right;
		}

		return res;
    }

	// 从根开始，先左，找到第一个左节点后，去找到该左节点的最右节点(右子树为空)，将该最右节点的右子树指向中序遍历的后继节点。继续往左到下一个左节点，此时以同样的方式去操作根节点的左子树；
	// 上一步操作如果根节点的左子树是叶子节点，那么这个时候叶子节点的右子树会指向到父节点。所以在进行寻找左节点的最右节点时，需要判断是否是同一节点。
	```
			1
		2		3
	0		4
	```

	vector<int> inorderTraversalNoStack(TreeNode *root) {
		if (!root) { return {}; }

		TreeNode *cur, *pre;
		cur = root;
		vector<int> res;
		while (cur) {
			if (!cur->left) {
				res.push_back(cur->val);
				cout << cur->val << endl;
				cur = cur->right;
			} else {
				pre = cur->left;
				while (pre->right && pre->right != cur) { pre = pre->right; }
				if (!pre->right) {
					pre->right = cur;
					cur = cur->left;
				} else {
					pre->right = NULL;
					res.push_back(cur->val);
					cout << cur->val << endl;
					cur = cur->right;
				}
			}
		}

		return res;
	}
};
