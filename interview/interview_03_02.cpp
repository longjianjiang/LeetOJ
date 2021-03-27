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
请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，该函数返回栈元素中的最小值。执行push、pop和min操作的时间复杂度必须为O(1)。
*/

class MinStack {
private:
	stack<int> minStack;
	stack<int> saveStack;
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
		saveStack.push(x);
		if (minStack.empty() || x <= minStack.top()) { minStack.push(x); }
    }

    void pop() {
		if (saveStack.top() == minStack.top()) { minStack.pop(); }
		saveStack.pop();
    }

    int top() {
		return saveStack.top();
    }

    int getMin() {
		return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
