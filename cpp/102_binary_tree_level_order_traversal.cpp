/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 给定一颗二叉树，让我们返回其层结构，一个二维数组
// 默认打印层序遍历使用一个队列，将节点依次入队，但是现在需要区分哪一层，所以开始的思路是入队后插入一个空标记用来区分层
// 不过其实并没有必要额外插入空，因为每次遍历队列中的元素就是表示该层的元素，因为随着节点的增加，插入的节点自然也会增加

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) { return res; }

		queue<TreeNode *> q;
		q.push(root);
		q.push(nullptr);

		while (!q.empty()) {
			vector<TreeNode *> nodes;
			TreeNode *top = q.front();

			while (top) {
				nodes.push_back(top);
				q.pop();
				top = q.front();
			}
			q.pop();

			vector<int> level;
			for (auto node: nodes) {
				level.push_back(node->val);
				if (node->left) { q.push(node->left); }
				if (node->right) { q.push(node->right); }
			}	
			if (!level.empty()) {
				res.push_back(level);
				q.push(nullptr);
			}
		}

		return res;
    }

	vector<vector<int>> levelOrder_2(TreeNode *root) {
		vector<vector<int>> res;
		if (!root) { return res; }

		queue<TreeNode *> q{{root}};
		while (!q.empty()) {
			vector<int> level;
			auto size = q.size();
			for (int i = 0; i < size; ++i) {
				TreeNode *node = q.front();
				q.pop();
				level.push_back(node->val);
  				if (node->left) { q.push(node->left); }
				if (node->right) { q.push(node->right); }
			}

			res.push_back(level);
		}
		
		return res;
	}
};
