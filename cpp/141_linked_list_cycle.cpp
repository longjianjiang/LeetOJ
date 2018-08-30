#include <iostream>
using namespace std;

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
   bool hasCycle(ListNode *head) {
        if (NULL == head) return false;
        ListNode *slow = head;
        ListNode *fast = head;
        bool isCycle = false;
       
        while(slow && fast) {
            slow = slow->next;
            fast = fast->next;
   
            if (NULL == fast) {
                return false;
            } else {
                fast = fast->next;
            }

            if (fast == slow) {
                isCycle = true;
                break;
            }
        }

        return isCycle; 
   }
   
   bool hasCycleVersionTwo(ListNode *head) {
        set<ListNode *> nodeSeen;
        while (head != NULL) {
             if (nodeSeen.count(head)) {
                 return true;
             } else {
                 nodeSeen.insert(head);
             }
             
             head = head->next;
        }
        return false;
   }
};


int main() {
   return 0;
}


