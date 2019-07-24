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

// 层序遍历，添加next节点即可。

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) { return root; }

        queue<Node *> q;
        q.push(root);
        int cnt = 1;

        while (!q.empty()) {
            Node *next_node = NULL;
            int sum = 0;
            for (int i = 0; i < cnt; ++i) {
                Node *node = q.front(); q.pop();
                node->next = next_node;
                next_node = node;

                if (node->right) { q.push(node->right); sum++; }
                if (node->left) { q.push(node->left); sum++; }
            }
            cnt = sum;
        }

        return root;
    }
};
