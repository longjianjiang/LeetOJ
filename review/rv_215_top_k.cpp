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
// 1 3 1 5 4 right = 2;
// 1 3 3 5 4 left = 1



// 3 4 2 1 5
// 3 2 4 1 5
// 3 2 1 4 5
// 1 2 3 4 5

int partition_2(vector<int>& nums, int left, int right) {
	int pivot = nums[left];
	while (left < right) {
		while (left < right && nums[right] >= pivot) { --right; }
		if (left < right) { nums[left] = nums[right]; }
		while (left < right && nums[left] <= pivot) { ++left; }
		if (left < right) { nums[right] = nums[left]; }
	}
	nums[left] = pivot;
	return left;
}

int partition(vector<int>& nums, int left, int right) {
	int nsize = nums.size();
	int pivot = nums[left];

	int pos = left;
	// 确定pivot的位置，出现一个小于pivot的值，idx右移一次。
	for (int i = left + 1; i <= right; ++i) {
		if (nums[i] < pivot) {
			++pos;
			if (i != pos) {
				swap(nums[pos], nums[i]);
			}
		}
	}
	swap(nums[left], nums[pos]);
	return pos;
}

int findKthLargest(vector<int>& nums, int k) {
	int nsize = nums.size();
	if (nsize == 0) { return -1; }
	if (k > nsize) { return -1; }

	int target = nsize - k;
	int l = 0, r = nsize - 1;
	while (l <= r) {
		int pos = partition(nums, l, r);
		if (pos == target) {
			return nums[pos];
		} else if (pos > target) {
			r = pos - 1;
		} else {
			l = pos + 1;
		}
	}
	return -1;
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
