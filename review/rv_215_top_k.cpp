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

// 2 3 1 5 4
// 2 1 3 5 4

// 3 4 2 1 5
// 3 2 4 1 5
// 3 2 1 4 5
// 1 2 3 4 5
int partition(vector<int>& nums, int left, int right) {
	int pivot = nums[left];
	int pos = left;

	for (int i = pos+1; i <= right; ++i) {
		if (nums[i] < pivot) {
			++pos;
			if (i != pos) { swap(nums[i], nums[pos]); }
		}
	}
	swap(nums[pos], nums[left]);
//	nums[pos] = pivot;

	return pos;
}

int findKthLargest(vector<int>& nums, int k) {
	int nsize = nums.size();
	int target = nsize - k;

	int left = 0, right = nsize-1;
	while (1) {
		int pos = partition(nums, left, right);
		if (pos == target) {
			return nums[target];
		} else if (pos > target) {
			right = pos - 1;
		} else {
			left = pos + 1;
		}
	}
}

// 3 4 5 2 1
int findKthLargest_heap(vector<int>& nums, int k) {
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int nsize = nums.size();

	for (int i = 0; i < k; ++i) {
		minHeap.push(nums[i]);
	}
	for (int i = k; i < nsize; ++i) {
		if (nums[i] > minHeap.top()) {
			minHeap.pop();
			minHeap.push(nums[i]);
		}
	}

	return minHeap.top();
}
