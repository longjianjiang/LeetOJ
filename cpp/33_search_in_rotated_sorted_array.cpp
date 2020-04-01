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

// 给定一个rotated sorted array，查找target所在的idx，没有返回-1
// 二分查找，选择是在有序一段还是无序一段进行继续二分；
// 1 2 3 4 5
// 2 3 4 5 1 
// 5 1 2 3 4
class Solution {
public:
    int search(vector<int>& nums, int target) {
		if (nums.empty()) { return -1; }
		int left = 0, right = nums.size()-1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) { return mid; }

			if (nums[left] < nums[mid]) { // left sorted
				if (nums[left] <= target && target < nums[mid]) {
					right = mid - 1;
				} else {
					left = mid + 1;
				}
			} else if (nums[left] > nums[mid]) { // right sorted
				if (nums[right] >= target && target > nums[mid]) {
					left = mid + 1;
				} else {
					right = mid - 1;
				}
			} else {
				++left;
			}
		}
		return -1;
    }
};
