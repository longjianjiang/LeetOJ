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

// 输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。

// 1> 使用堆；
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if (k > input.size()) { return {}; }

		priority_queue<int, vector<int>, greater<int>> minHeap;
		vector<int> res;
		for (auto num: input) { minHeap.push(num); }

		for (int i = 0; i < k; ++i) {
			int minValue = minHeap.top();
			minHeap.pop();
			res.push_back(minValue);
		}
		return res;
    }
};
