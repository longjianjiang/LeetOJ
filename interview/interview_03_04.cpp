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

// 实现一个MyQueue类，该类用两个栈来实现一个队列。
// 1> 插入的时候正常插入，pop的时候如果栈为空，将原有栈进行出栈。
// 1 2 3 4 5
class MyQueue {
private:
	stack<int> s1;
	stack<int> s2;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
		s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
		tryUpdateStackTwo();	
		if (s2.empty()) { return -1; }

		int res = s2.top();
		s2.pop();
		return res;
    }

    /** Get the front element. */
    int peek() {
		tryUpdateStackTwo();
		if (s2.empty()) { return -1; }

		return s2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
		return s1.empty() && s2.empty();
    }

	void tryUpdateStackTwo() {
		if (s2.empty()) {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}
	}
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
