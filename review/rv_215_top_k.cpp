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

// {3, 3, 4, 3, 3}
// {3, 6, 5, 0, 1}
// 3 0 5 6 1
// 3 0 1 6 5
int partition(vector<int>& nums int left, int right) {
	int pivot = nums[left];
	int pos = left;

	for (int i = left+1; i <= right; ++i) {
		int num = nums[i];
		if (num <= pivot) {
			++pos;
			if (i != pos) { swap(nums[i], nums[pos]); }
		}
	}
	swap(nums[pos], nums[left]);

	return pos;
}

int findKthLargest(vector<int>& nums, int k) {
	int nsize = nums.size();
	int target = nsize - k;
	int left = 0, right = nsize - 1;
	while (1) {
		int pos = partition(nums, left, right);
		if (pos == target) {
			return nums[pos];
		} else if (pos < target) {
			left = pos + 1;
		} else {
			right = pos - 1;
		}
	}
}
