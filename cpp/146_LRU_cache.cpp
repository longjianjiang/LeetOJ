#include <iostream>
#include <unordered_map>
using namespace std;

// 本题要求实现一个LRU Cache（Least Recently Used）
// 当插入一个数据时，首先从map中判断是否存在，如果不存在将这个数据插入链表的头部，如果此时size超过最大则将链表最后一个节点删除；如果存在将链表中该节点移到头部；
// 当读取一个数据时，从map中查找，如果存在返回并且将该节点移动到链表的头部；否则没找到返回-1
// 主要就是当size存满时，将最近最少使用的节点移除
// 下面是使用map和双向链表进行实现的一个答案

#include <iostream>
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
    int count;
    int size;
    unordered_map<int,Node *> mp;
    Node *cacheHead;
    Node *cacheTail;
    
    void bringNodeToHead(Node *node) {
        if (cacheHead == node) return;
        
        if (cacheTail == node) {
            cacheTail = node->prev;
            cacheTail->next = NULL;
        } else {
            node->next->prev = node->prev;
            node->prev->next = node->next;
        }
        
        node->next = cacheHead;
        node->prev = NULL;
        cacheHead->prev = node;
        cacheHead = node;
    }
    
    void insertNodeAtHead(Node *node) {
        mp[node->key] = node;
        count++;
        if (cacheHead) {
            node->next = cacheHead;
            cacheHead->prev = node;
            cacheHead = node;
        } else {
            cacheHead = cacheTail = node;
        }
    }
    Node *removeTailNode() {
        if (cacheTail == NULL) return NULL;
        Node *tail = cacheTail;
        mp.erase(cacheTail->key);
        count--;
        if (cacheHead == cacheTail) {
            cacheHead = cacheTail = NULL;
        } else {
            cacheTail = cacheTail->prev;
            cacheTail->next = NULL;
        }
        return tail;
    }
public:
    LRUCache(int capacity) {
        size = capacity;
        count = 0;
        cacheHead = NULL;
        cacheTail = NULL;
    }
    
    int get(int key) {
        if (cacheHead == NULL) return -1;
        unordered_map<int,Node *>::iterator it = mp.find(key);
        if (it == mp.end()) {
            return -1;
        } else {
            Node *node = it->second;
            bringNodeToHead(node);
        }
        return cacheHead->value;
    }
    
    void put(int key, int value) {
        unordered_map<int, Node *>::iterator it = mp.find(key);
        if (it == mp.end()) {
            if (count == size) {
                removeTailNode();
            }
            Node *node = (Node *)malloc(sizeof(Node));
            node->key = key;
            node->value = value;
            node->prev = NULL;
            node->next = NULL;
            insertNodeAtHead(node);
        } else {
            Node *node = it->second;
            node->value = value;
            bringNodeToHead(node);
        }
        
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout<<cache.get(1)<<endl;
    cache.put(3, 3);
    cout<<cache.get(2)<<endl;
    cache.put(4, 4);
    cout<<cache.get(1)<<endl;
    cout<<cache.get(3)<<endl;
    cout<<cache.get(4)<<endl;
    
    
    return 0;
}