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
三合一。描述如何只用一个数组来实现三个栈。

你应该实现push(stackNum, value)、pop(stackNum)、isEmpty(stackNum)、peek(stackNum)方法。stackNum表示栈下标，value表示压入的值。

构造函数会传入一个stackSize参数，代表每个栈的大小。

当栈为空时`pop, peek`返回-1，当栈满时`push`不压入元素。
*/

// 用额外的数组记录下，数组中三段的索引，操作即可；
class TripleInOne {
private:
	vector<int> arr;
	int stackSize;
	int stackNum = 3;
	vector<int> top;

	bool isFull(int stackNum) {
		int idx = top[stackNum];
		int endIdx = (stackNum + 1) * stackSize;

		return idx == endIdx;
	}

public:
    TripleInOne(int stackSize) {
		this->stackSize = stackSize;
		int nsize = stackSize * stackNum;
		for (int i = 0; i < nsize; ++i) { arr.push_back(0); }
		for (int i = 0; i < stackNum; ++i) { top.push_back(i * stackSize); }
    }

	// 1 2 3 4 5 6 7 8 9
    void push(int stackNum, int value) {
		if (isFull(stackNum)) { return; }

		arr[top[stackNum]++] = value;
    }

    int pop(int stackNum) {
		if (isEmpty(stackNum)) { return -1; }

		int idx = top[stackNum];
		top[stackNum]--;
		return arr[top[stackNum]];
    }

    int peek(int stackNum) {
		if (isEmpty(stackNum)) { return -1; }

		return arr[top[stackNum]-1];
    }

    bool isEmpty(int stackNum) {
		int idx = top[stackNum];
		int startIdx = stackNum * stackSize;

		return idx == startIdx;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */
