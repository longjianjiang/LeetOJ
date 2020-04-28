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
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
注意：保证测试中不会当栈为空的时候，对栈调用pop()或者min()或者top()方法
*/

// 因为存在pop，所以需要一个存储额外的最小的列表；
class Solution {
	stack<int> stk;
	stack<int> minStk;
public:
    void push(int value) {
		stk.push(value);
		if (minStk.empty() || value < minStk.top()) {
			minStk.push(value);
		}
    }
    void pop() {
		int top = stk.top();
		stk.pop();
		if (top == minStk.top()) {
			minStk.pop();
		}
    }
    int top() {
		return stk.top();
    }
    int min() {
		if (minStk.empty()) { return stk.top(); }
		return minStk.top();
    }
};
// 3 1 5 0
