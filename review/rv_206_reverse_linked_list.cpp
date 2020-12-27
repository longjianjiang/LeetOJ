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

// 1-2-3-4-5
ListNode* reverse_list_1(ListNode *list) {
	if (!list) { return NULL; }
	ListNode *node = NULL;
	while (list) {
		ListNode *tmp = list->next;
		list->next = node;
		node = list;
		list = tmp;
	}

	return node;
}

// 1-2-3-4-5
// 1-2
// 1 2
// 递归方式，一个节点，两个节点处理好了，递归的处理多个节点。
ListNode* reverse_list_2(ListNode *list) {
	if (!list) { return NULL; }
	if (!list->next) { return list; }

	ListNode *reversed = reverse_list_2(list->next);
	list->next->next = list;
	list->next = NULL;

	return reversed;
}

