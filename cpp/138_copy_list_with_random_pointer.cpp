#include <iostream>
#include <unordered_map>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

// 深拷贝一个链表（多了一个random节点，指向链表中任意节点或null）
// 遍历原链表，第一次遍历构造next，同时用map存下原节点和新节点的对应关系，第二次利用map构造random即可

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {        
    	if (!head) return head;

    	RandomListNode *res = new RandomListNode(head->label);
    	RandomListNode *node = res;
    	RandomListNode *cur = head->next;

    	unordered_map<RandomListNode *, RandomListNode *> dict;
    	dict[head] = res;

    	while(cur) {
    		RandomListNode *t = new RandomListNode(cur->label);
    		node->next = t;
    		dict[cur] = t;
    		node = node->next;
    		cur = cur->next;
    	}

    	node = res;
    	cur = head;

    	while(node) {
    		node->random = dict[cur->random];
    		node = node->next;
    		cur = cur->next;
    	}

    	return res;
    }
};