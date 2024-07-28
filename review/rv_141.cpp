/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            return false;
        }
        /*
        unordered_map<ListNode *, int> dict;
        while (head) {
            if (dict.find(head) == dict.end()) {
                dict[head] = 1;
            } else {
                return true;
            }
            head = head->next;
        }
        return false;
        */

        auto slow = head->next;
        auto fast = head->next->next;
        
        while (slow && fast && slow != fast) {
            slow = slow->next;
            auto tmp = fast->next;
            if (tmp) {
                fast = tmp->next;
            } else {
                fast = NULL;
            }
        }

        if (slow != NULL && fast != NULL) {
            return true;
        }
        return false;
    }
    /*
    slow = 2, fast = NULL;
    */
};
// slow = 2, fast = 0;
// slow = 0, fast = 2;
// slow = -4; fast = -4;

// slow = 3, fast = -4;
// slow = 2, fast = 2
