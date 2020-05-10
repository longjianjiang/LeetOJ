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

// 输入两个链表，找出它们的第一个公共结点。（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

// 1> 暴力，因为长度可能不一样，先计算出长度，从同一起点开始移动，判断节点是否相同；
// 2> 环，各自从起点开始遍历，如果到尾，设置为对方的头继续遍历，最后相交可能是公共节点也可能是空，因为走的距离是一样的；
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
		if (!pHead1 || !pHead2) { return NULL; }

		auto node1 = pHead1, node2 = pHead2;
		while (node1 != node2) {
			node1 = node1 ? node1->next : pHead2;
			node2 = node2 ? node2->next : pHead1;
		}
		return node1;
    }
};
