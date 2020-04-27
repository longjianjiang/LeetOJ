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
};*/

// 将二叉树，变换为对应的镜象二叉树；
class Solution {
public:
    void Mirror(TreeNode *root) {
		if (!root) { return; }
		if (!root->left && !root->right) { return; }

		TreeNode *tmp = root->left;
		root->left = root->right;
		root->right = tmp;

		Mirror(root->left);
		Mirror(root->right);
    }
};
