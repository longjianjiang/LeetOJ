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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 实现一种算法，删除单向链表中间的某个节点（即不是第一个或最后一个节点），假定你只能访问该节点。
// 节点值的替换，来进行删除。
// 1-2-3-4-5 => 1-2-4-5
// 1-2-4-4-5 => 1-2-4-5
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        auto tmp = node->next;
        node->next = tmp->next;
    }
}
