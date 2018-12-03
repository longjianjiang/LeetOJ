/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 和21题类似，不过本题给的是一个链表数组，让我们将数组中链表进行合并
// 利用最小堆，最小堆的根节点是最小的数，所以每次取堆中最小的节点，插入到新链表，
// 如果该节点有next节点，将next节点放进堆中，直到堆中数据为空。

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {        
        vector<ListNode *> minHeap;
        for (auto list: lists) {
            if (list != nullptr) {
                minHeap.push_back(list);
            }
        }
        make_heap(minHeap.begin(), minHeap.end(), compare);
        
        ListNode *res = new ListNode(-1);
        ListNode *cur = res;
        
        while (!minHeap.empty()) {
            pop_heap(minHeap.begin(), minHeap.end(), compare);
            ListNode *node = minHeap.back();
            minHeap.pop_back();
            
            cur->next = node;
            cur = cur->next;
            
            
            if (node->next) {
                minHeap.push_back(node->next);
                push_heap(minHeap.begin(), minHeap.end(), compare);
            }
        }
        
        return res->next;
    }
private:
    static bool compare(ListNode *p1, ListNode *p2) {
        return p1->val > p2->val;
    }
};