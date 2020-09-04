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
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *reverse(ListNode *head) {
		ListNode* res = NULL;
		while (head) {
			auto next = head->next;
			head->next = res;
			res = head;
			head = next;
		}

		return res;
	}

    void reorderList(ListNode* head) {
		if (!head || !head->next || !head->next->next) { return; }

		// split two list;
		auto segOneHead = head;
		ListNode *segOneTail = NULL;
		auto slow = head, fast = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			segOneTail = slow;
		}
        // reverse second list;
        auto segTwoHead = segOneTail->next;
        segTwoHead = reverse(segTwoHead);

        // disconnect first list;
        segOneTail->next = NULL;

		// merge two list;
		while (segTwoHead) {
			auto segOneNext = segOneHead->next;
			auto segTwoNext = segTwoHead->next;

			segOneHead->next = segTwoHead;
			segTwoHead->next = segOneNext;
			segOneHead = segOneNext;
			segTwoHead = segTwoNext;
		}
    }
};

void unit_test() {
}

int main() {
	unit_test();
	return 0;
}
