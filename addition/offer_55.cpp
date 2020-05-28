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
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/

// 给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

// 1> 使用set；
// 2> 使用双指针，环的找法；[ref](https://zhuanlan.zhihu.com/p/103626709)
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
		unordered_set<ListNode *> us;
		auto node = pHead;
		while (node) {
			if (us.find(node) != us.end()) { return node; }
			us.insert(node);
			node = node->next;
		}

		return NULL;
	}
};
