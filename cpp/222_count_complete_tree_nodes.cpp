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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 统计完全二叉树节点个数
// 1> 层序遍历；

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) { return 0; }
        queue<TreeNode *> q;
        q.push(root);

		int cnt = 0;
		int size = 1;
        while (!q.empty()) {
			int updated = 0;
			for (int i = 0; i < size; ++i) {
				++cnt;
				auto node = q.front(); q.pop();
				if (node->left) { q.push(node->left); ++updated; }
				if (node->right) { q.push(node->right); ++updated; }
			}
			size = updated;
        }
		return cnt;
    }
};
