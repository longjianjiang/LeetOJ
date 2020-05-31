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
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
*/

// 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

/*
		8
	6		10
 5	   7  9    11		
*/

// 当前节点存在右子树，找右子树的最左节点；
// 找父节点，如果父节点的left就是node，返回父节点，否则就是最右叶子节点；
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* node) {
		if (!node) { return NULL; }

		TreeLinkNode *nodeNext = NULL;

		if (node->right) { // right child's leftest child;
			auto tmp = node->right;
			while (tmp->left) {
				tmp = tmp->left;
			}
			nodeNext = tmp;
		} else {
			auto tmp = node;
			auto nodeParent = node->next;

			while (nodeParent && nodeParent->right == tmp) {
				tmp = nodeParent;
				nodeParent = nodeParent->next;
			}
			nodeNext = nodeParent;
			/*
			if (!nodeParent) { return NULL; }
			if (nodeParent->left == node) { return nodeParent; }

			tmp = nodeParent;
			nodeParent = nodeParent->next;
			while (nodeParent) {
				if (nodeParent->right == tmp) { return NULL; }
				tmp = nodeParent;
				nodeParent = nodeParent->next;
			}
			nodeNext = tmp;
			*/
		}

		return nodeNext;
	}
};
