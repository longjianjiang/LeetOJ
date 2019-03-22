#include <iostream>
#include <stack>

using namespace std;

// 要求实现一个栈，除了常规的操作，多了一个取栈中最小值的操作。
// 额外使用一个栈，维护一个倒序的列表用于返回最小的元素。

class MinStack1 {
public:
	MinStack1() = default;

	void push(int x) {
		s1.push(x);
		if (s2.empty() || x <= s2.top()) { s2.push(x); }
	}

	void pop() {
		if (s1.top() == s2.top()) { s2.pop(); }
		s1.pop();
	}

	int top() {
		return s1.top();
	}

	int getMin() {
		return s2.top();
	}
private:
	stack<int> s1, s2;
};

// 也可以使用一个额外的最小数字来作为标记，进栈时判断元素是否不大于标记，首先将标记入栈，然后将元素入栈；
// 而出栈时则取top后出栈一次，然后判断top与标记是否相等，更新标记进行第二次出栈

class MinStack {
public:
	MinStack() { min_val = INT_MAX; }

	void push(int x) {
		if (x <= min_val) {
			st.push(min_val);
			min_val = x;
		}
		st.push(x);
	}

	void pop() {
		int top = st.top(); 
		st.pop();
		if (top == min_val) {
			min_val = st.top();
			st.pop();
		}
	}

	int top() { return st.top(); }

	int getMin() { return min_val; }

private:
	stack<int> st;
	int min_val;
};
