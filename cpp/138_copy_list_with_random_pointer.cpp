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

    // 前面一种方法使用了map，下面这种方法则不需要额外的空间，参考自（https://fisherlei.blogspot.com/2013/11/leetcode-copy-list-with-random-pointer.html）
    // 分三步：
    // 1. 首先在原链表中每个节点后复制一个节点
    // 2. 将复制的节点根据原链表中的random指定到对应的复制节点
    // 3. 最后将链表断开后，返回复制的节点链表即可

    RandomListNode *copyRandomListVersion2(RandomListNode *head) {
    	if (!head) return head;

    	RandomListNode *cur = head;
    	while(cur) {
    		RandomListNode *t = new RandomListNode(cur->label);
    		t->next = cur->next;
    		cur->next = t;
    		cur = t->next;
    	}

    	cur = head;
    	while(cur) {
    		RandomListNode *random = cur->random;
    		if (random) cur->next->random = random->next;
    		cur = cur->next->next;
    	}

    	cur = head;
    	RandomListNode *res = cur->next;
    	while(cur) {
    		RandomListNode *t = cur->next;
    		cur->next = t->next;
    		if (t->next) t->next = t->next->next;
    		cur = cur->next;
    	}

    	return res;
    }
};