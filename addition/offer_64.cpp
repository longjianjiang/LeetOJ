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

// 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
// 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。

// 1> 遍历窗口寻找最大值；
// 2> 使用堆来存，不过因为涉及到头删尾插，并不太方便；
// 3> 双端队列；插入的时候保证front是最大元素
class Solution {
public:
	void addNumToQueue(deque<int>& q, int num) {
		while (!q.empty() && num > q.back()) {
			q.pop_back();
		}
		q.push_back(num);
	}

    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
		vector<int> res;
		int nsize = num.size();
		if (size == 0 || nsize == 0 || size > nsize) { return res; }

		deque<int> q;
		for (int i = 0; i < size; ++i) {
			addNumToQueue(q, num[i]);
		}
		res.push_back(q.front());
		for (int i = 0; i < nsize-size; ++i) {
			if (q.front() == num[i]) { q.pop_front(); } // 移除不在窗口的的front元素；
			addNumToQueue(q, num[i+size]);
			res.push_back(q.front());
		}
		
		return res;
	}
};

