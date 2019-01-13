#include <iostream>
#include <vector>

using namespace std;

// 给定一个链表，要求我们返回倒序后的节点数组。

// 一个直观的思路就是首先将链表遍历，存入数组，然后将数组倒序即可，
// 或者遍历数组将数字存到栈，然后依次出栈即可

vector<int> printListFromTailToHead(ListNode* head) {
	vector<int> res;
	while (head) {
		res.push_back(head->val);
		head = head->next;
	}
	reverse(res.begin(), res.end());
	return res;
}