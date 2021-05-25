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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void show_arr_one_dimensional(vector<int> arr) {
	cout << "[";
	for (int i = 0; i < arr.size(); ++i) {
		int num = arr[i];
		if (i == arr.size()-1) {
			cout << num;
		} else {
			cout << num << " ";
		}
	}
	cout << "]\n";
}

void showLinkedList(ListNode *root) {
	if (!root) { cout << "Empty linked list.\n"; }
	vector<int> arr;
	auto node = root;
	while (node) {
		arr.push_back(node->val);
		node = node->next;
	}
	show_arr_one_dimensional(arr);
}

ListNode *reverseList(ListNode *root) {
	if (!root || !root->next) { return root; }

	ListNode *res = NULL;
	while (root) {
		ListNode *tmp = root->next;
		root->next = res;
		res = root;
		root = tmp;
	}

	return res;
}

ListNode *removeDuplicate(ListNode *root) {
	if (!root || !root->next) { return root; }

	auto p = root;
	auto q = p->next;

	while (p && q) {
		if (p->val != q->val) {
			p = p->next;
			q = q->next;
		} else {
			while (q->next && q->next->val == p->val) {
				q = q->next;
			}
			p->next = q->next;
			q = p->next;
		}
	}

	return root;
}

ListNode *removeDuplicateAtAll(ListNode *root) {
	if (!root || !root->next) { return root; }

	ListNode *tmp = new ListNode(root->val - 1);
	tmp->next = root;

	ListNode *first = tmp;
	ListNode *second = root;
	ListNode *third = NULL;

	while (second) {
		auto node = root->next;
		if (!node) { break; }

		if (second->val == node->val) {
			third = second;
		} else {
			if (third) {
				first->next = third->next;
				third = NULL;
			} else {
				first = second;
			}
		}

		second = node;
	}
	if (third) { first->next = third->next; }

	return tmp->next;
}

ListNode *getLinkedList() {
	ListNode *root = new ListNode(1);
	root->next = new ListNode(2);
	root->next->next = new ListNode(2);
	root->next->next->next = new ListNode(3);
	root->next->next->next->next = new ListNode(3);
	root->next->next->next->next->next = new ListNode(4);

	return root;
}

int main() {

	auto root = getLinkedList();
	showLinkedList(root);
	auto res = removeDuplicateAtAll(root);
	showLinkedList(res);

	return 0;
}

// 1-2-2-2-3-3-4
ListNode *removeDuplicate(ListNode *root) {
	if (!head || !head->next) { return head; }

	ListNode *left = head, *right = head->next;

	while (left && right) {
		if (left->val == right->val) {
			while (right->next && right->next->val == left->val) {
				right = right->next;
			}
			left->next = right->next;
			right = left->next;
		} else {
			left = left->next;
			right = right->next;
		}
	}

	return head;
}

// 1-2-2-2-3-3-4
ListNode *removeDuplicateAtAll(ListNode *head) {
	if (!head || !head->next) { return head; }

	auto tmp = new ListNode(head->val - 1);
	tmp->next = head;

	auto p = tmp, q = tmp->next;
	while (p && q) {
		while (q->next && q->next->val == p->val) {
			q = q->next;
		}
		if (p->next == q) {
			p = p->next;
		} else {
			p->next = q->next;
		}
		q = p->next;
	}

	return tmp->next;
}

// 1-2-3-4-5, n = 3;
// 
ListNode* removeNthFromEnd(ListNode* head, int n) {
	if (!head) { return head; }

	auto p = head, q = head;

	for (int i = 0; i < n; ++i) { q = q->next; }
	if (!q) { return head->next; }

	while (q->next) {
		p = p->next;
		q = q->next;
	}

	p->next = p->next->next;

	return head;
}