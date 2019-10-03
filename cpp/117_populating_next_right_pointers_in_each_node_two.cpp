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
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

// 为二叉树每一层添加next节点。
// 1> 和116 类似，使用层序遍历，每一层进行添加next节点；
// 2> 还是层序遍历，不使用队列，使用节点来进行next节点的构建，从根开始，依次连接该节点的左右子树的next，直到最右叶子；
class Solution {
public:
    Node* connect(Node* root) {
		Node *node = new Node(-1, NULL, NULL, NULL), *cur = node, *head = root;

		while (head) {
			if (head->left) {
				cur->next = head->left;
				cur = cur->next;
			}
			if (head->right) {
				cur->next = head->right;
				cur = cur->next;
			}
			head = head->next;
			if (!head) {
				cur = node;
				head = cur->next;
				cur->next = NULL;
			}
		}

		return root;
    }
};
