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

struct Node {
    int key;
    int value;
    Node *prev;
    Node *next;
};

class LRUCache {
private:
	int size;
	int count;
	unordered_set<int, Node *> dict;
	Node *head;
	Node *tail;

	// 1-2-3-4
	void bringNodeToHead(Node *node) {
		if (head == node) { return; }

		if (tail == node) {
			tail = tail->prev;
			tail->next = NULL;
		} else {
			node->prev->next = node->next;
			node->next->prev = node->prev;
		}

		node->next = head;
		node->prev = NULL;
		head->prev = node;
		head = node;
	}

	void removeTailNode() {
		if (!tail) { return; }


	}

	void insertNodeAtHead(Node *node) {
	}

public:
    LRUCache(int capacity) {
		size = capacity;
		count = 0;
		head = NULL;
		tail = NULL;
    }

    int get(int key) {
    }

    void put(int key, int value) {

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
