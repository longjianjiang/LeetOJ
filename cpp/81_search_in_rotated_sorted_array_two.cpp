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

// 同33，给定rotated sorted array(可能存在重复元素)和target，要求查找是否存在；
class Solution {
public:
    bool search(vector<int>& nums, int target) {
		if (nums.empty()) { return false; }
		int left = 0, right = nums.size()-1;

		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (nums[mid] == target) { return true; }

			if (nums[left] < nums[mid]) { // left sorted
				if (target < nums[mid] && nums[left] <= target) {
					right = mid - 1;
				} else {
					left = mid + 1;
				}
			} else if (nums[left] > nums[mid]) {
				if (target <= nums[right] && nums[mid] < target) {
					left = mid + 1;
				} else {
					right = mid - 1;
				}
			} else {
				++left;
			}
		}

		return false;
    }
};
