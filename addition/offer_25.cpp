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
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针random指向一个随机节点），
请对此链表进行深拷贝，并返回拷贝后的头结点。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/

/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/

// 1> 首先拷贝链表的节点，同时map记录下新旧节点的关系，第二次遍历进行设置random节点；
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead) {
		if (!pHead) { return NULL; }

		unordered_map<RandomListNode*, RandomListNode*> dict;
		RandomListNode *newHead = NULL, *newNode;
		RandomListNode *curNode = pHead;

		while (curNode) {
			auto tmpNode = new RandomListNode(curNode->label);
			dict[curNode] = tmpNode;

			if (!newHead) {
				newHead = tmpNode;
			} else {
				newNode->next = tmpNode;
			}
			newNode = tmpNode;

			curNode = curNode->next;
		}

		curNode = pHead;
		newNode = newHead;
		while (curNode && newNode) {
			auto random = curNode->random;
			auto newRandom = dict[random];
			newNode->random = newRandom;

			curNode = curNode->next;
			newNode = newNode->next;
		}

		return newHead;
    }

	// 1-2-3-4-5
	// 1-1'-2-2'-3-3'-4-4'-5-5'
	RandomListNode * clone(RandomListNode *head) {
		if (!head) { return NULL; }

		auto node1 = head, node2 = head;
		while (node1) {
			node2 = new RandomListNode(node1->label);
			node2->next = node1->next;

			node1->next = node2;
			node1 = node2->next;
		}

		node1 = head;
		while (node1) {
			auto tmpNode = node1->random;
			if (tmpNode) {
				node1->next->random = tmpNode->next;
			} else {
				node1->next->random = NULL;
			}

			node1 = node1->next->next;
		}

		node1 = head;
		node2 = head->next;
		auto res = node2;
		while (node1 && node2) {
			node1->next = node2->next;

			if (node2->next) {
				node2->next = node2->next->next;
			} else {
				node2->next = NULL;
			}

			node1 = node1->next;
			node2 = node2->next;
		}

		return res;
	}
};
