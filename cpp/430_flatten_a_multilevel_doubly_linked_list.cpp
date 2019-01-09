#include <iostream>

using namespace std;

// 给定一个带child节点的双链表 flatten 成一维的双链表
// 直接的思路的就是遍历，构建一个新的一维的双链表
// 两种方式：一种一层一层的 flatten， 另一种直接flatten到最底层。

class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        Node *cur = head;
        while (cur) {
            if (cur->child) {
                Node *next = cur->next;
                Node *levelTail = cur->child;
                while (levelTail->next) { levelTail = levelTail->next; }
                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = NULL;

                levelTail->next = next;
                if (next) { next->prev = levelTail; }
            }
            cur = cur->next;
        }
        return head;
    }

    Node* flattenVersion2(Node* head) {
        Node *cur = head;
        while (cur) {
            if (cur->child) {
                Node *next = cur->next;
                cur->child = flattenVersion2(cur->child);
                Node *levelTail = cur->child;
                while (levelTail->next) { levelTail = levelTail->next; }
                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = NULL;

                levelTail->next = next;
                if (next) { next->prev = levelTail; }
            }
            cur = cur->next;
        }
        return head;
    }
};