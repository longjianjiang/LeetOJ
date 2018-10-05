#include<iostream>

using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

// 给定两个链表，求交叉节点，要求O(n) 时间复杂度，O(1)空间复杂度

// 一个简单的思路，首先求两条链表的长度，如果不一致，让长的往前移动和短的在同一起点，然后遍历直到发现交叉点，否则返回NULL即可

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;

        int lenA = getLength(headA), lenB = getLength(headB);
        if (lenA < lenB) {
            for(int i = 0; i < lenB - lenA; ++i) { headB = headB->next; }
        } else {
            for(int i = 0; i < lenA - lenB; ++i) { headA = headA->next; }
        }

        while(headA && headB && headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA ? headA : NULL;
    }

    // 第二种思路利用环，用两个指针分别指向两个链表的头，依次遍历，当某个到了某个节点的尾，将指针指向另一个链表的头
    // 当两个指针相等时有两种情况，如果两个链表有交叉，那么相等时就是在交叉点，否则就是在最后的NULL节点处
    // 因为两个指针所走的路程都是一样的
    
    ListNode *getIntersectionNodeVersion2(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;

        ListNode *p = headA, q = headB;
        while (p != q) {
            p = p ? p->next : headB;
            q = q ? q->next : headA;
        }

        return p;
    }
private:
    int getLength(ListNode *head) {
        int len = 0;
        while(head) {
            len += 1;
            head = head->next;
        }

        return len;
    }
};