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

// 设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
		int nsize = arr.size();
		if (nsize == 0 || k == 0) { return {}; }
		
		priority_queue<int, vector<int>> maxHeap;

		for (int i = 0; i < k; ++i) { maxHeap.push(arr[i]); }
		for (int i = k; i < nsize; ++i) {
			if (maxHeap.top() > arr[i]) {
				maxHeap.pop();
				maxHeap.push(arr[i]);
			}
		}

		vector<int> res;
		while (!maxHeap.empty()) {
			res.push_back(maxHeap.top());
			maxHeap.pop();
		}

		return res;
    }
};
