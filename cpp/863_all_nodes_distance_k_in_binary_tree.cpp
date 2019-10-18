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

// 给定一颗二叉树，树中一个节点，K，要求返回树中所有节点到target的path为K的集合。
// dfs 构建一个邻接矩阵，bfs 遍历邻接矩阵即可找到path为K的列表。
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
		if (!root) { return {}; }

		vector<int> res;
		unordered_map<TreeNode *, vector<TreeNode *>> um;
		queue<TreeNode *> q ( {target} );
		unordered_set<TreeNode *> visited ( {target} );

		// dfs
		connect(NULL, root, um);	
		// bfs
		while (!q.empty()) {
			if (K == 0) {
	            for (int i = q.size(); i > 0; --i) {
	                res.push_back(q.front()->val); q.pop();
	            }
				return res;
			}
			for (int i = q.size(); i > 0; --i) {
				auto node = q.front(); q.pop();
				for (auto n : um[node]) {
					if (visited.find(n) != visited.end()) { continue; }
					visited.insert(n);
					q.push(n);
				}
			}
			--K;
		}
		return res;
    }

	void connect(TreeNode* parent, TreeNode* child, unordered_map<TreeNode *, vector<TreeNode *>>& um) {
		if (parent && child) {
			um[parent].push_back(child);
			um[child].push_back(parent);
		}

		if (child->left) { connect(child, child->left, um); }
		if (child->right) { connect(child, child->right, um); }
	}
};
