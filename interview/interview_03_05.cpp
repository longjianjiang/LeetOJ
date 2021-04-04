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

/*
栈排序。 编写程序，对栈进行排序使最小元素位于栈顶。最多只能使用一个其他的临时栈存放数据，但不得将元素复制到别的数据结构（如数组）中。该栈支持如下操作：push、pop、peek 和 isEmpty。当栈为空时，peek 返回 -1。
*/

// 使用两个栈存，一个栈存逆序的，另一个是升序的，同时升序的元素要小于降序的。
// pop的时候，首先将升序的出栈到降序栈中，此时降序栈就是有序的。
class SortedStack {
private:
	stack<int> s1;
	stack<int> s2;
public:
    SortedStack() {

    }

    void push(int val) {
		// case 4 2 3 1
		while (!s2.empty() && s2.top() > val) {
			s1.push(s2.top());
			s2.pop();
		}
		while (!s1.empty() && s1.top() < val) {
			s2.push(s1.top());
			s1.pop();
		}
		s1.push(val);
    }

	void updateStack() {
		while (!s2.empty()) {
			s1.push(s2.top());
			s2.pop();
		}
	}

    void pop() {
		updateStack();
		if (s1.empty()) { return; }
		s1.pop();
    }

    int peek() {
		updateStack();
		if (s1.empty()) { return -1; }
		return s1.top();
    }

    bool isEmpty() {
		return s1.empty() && s2.empty();
    }
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */
