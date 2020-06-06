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

// 到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

// 1> 朴素，数组存储所有元素，返回的时候，先排序然后计算中位数；
// 2> 链表的方式，每次插入寻找到合适的位置插入；
// 3> 堆，把有序的数组拆分成两份，前半段用最大堆存，后半段用最小堆来存，这样可以快速的获取到中位数；所以插入的时候需要保证最大堆的元素要小于最小堆中的元素；

class Solution {
	priority_queue<int, vector<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int count = 0;
public:
    void Insert(int num) {
		++count;
		if (count & 1) {
			if (minHeap.size() > 0 && num > minHeap.top()) {
				minHeap.push(num);
				num = minHeap.top();
				minHeap.pop();
			}
			maxHeap.push(num);
		} else {
			if (maxHeap.size() > 0 && num < maxHeap.top()) {
				maxHeap.push(num);
				num = maxHeap.top();
				maxHeap.pop();
			}
			minHeap.push(num);
		}
	}

    double GetMedian() {
		if (count & 1) {
			return maxHeap.top();
		} else {
			return (minHeap.top() + maxHeap.top()) / 2.0;
		}
	}
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
