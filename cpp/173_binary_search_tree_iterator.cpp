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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 给定bst，实现迭代器，next()方法依次返回最小的节点数字；hasNext()返回是否还有下一个最小的；
// 初始化中序遍历拿到有序数组即可；
class BSTIterator {
private:
	vector<int> arr;
	int idx = 0;
	void dfs(TreeNode *root, vector<int>& arr) {
		if (!root) { return; }
		dfs(root->left, arr);
		arr.push_back(root->val);
		dfs(root->right, arr);
	}

	void dfs_iterate(TreeNode *root, vector<int>& arr) {
		if (!root) { return; }

		auto node = root;
		stack<TreeNode *> stk;
		while (!stk.empty() || node) {
			if (node) {
				stk.push(node);
				node = node->left;
			} else {
				node = stk.top(); stk.pop();
				arr.push_back(node->val);
                node = node->right;
			}
		}
	}
public:
    BSTIterator(TreeNode* root) {
		dfs(root, arr);
    }
    
    /** @return the next smallest number */
    int next() {
		return arr[idx++];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
       return idx < arr.size(); 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
