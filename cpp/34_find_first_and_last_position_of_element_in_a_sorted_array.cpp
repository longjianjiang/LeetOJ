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

// 给定有序数组，target的左右边界，没有返回-1。
// 也就是数组中存在重复元素，让我们去找最先出现的和最后出现的。
// 依然二分，当相等时判断，尝试对mid继续进行二分。
class Solution {
public:
	int findMostLeft(vector<int>& nums, int target) {
		int l = 0, h = nums.size()-1;
		while (l <= h) {
			int mid = l + (h-l) / 2;
			if (nums[mid] == target) {
				if (mid == 0 || nums[mid-1] != target) {
					return mid;
				} else {
					h = mid-1;
				}
			} else if (nums[mid] > target) {
				h = mid-1;
			} else {
				l = mid+1;
			}
		}
		return -1;
	}

	int findMostRight(vector<int>& nums, int target) {
		int l = 0, h = nums.size()-1;
		while (l <= h) {
			int mid = l + (h-l) / 2;
			if (nums[mid] == target) {
				if (mid == nums.size()-1 || nums[mid+1] != target) {
					return mid;
				} else {
					l = mid+1;
				}
			} else if (nums[mid] > target) {
				h = mid-1;
			} else {
				l = mid+1;
			}
		}
		return -1;
	}

    vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res;

		res.push_back(findMostLeft(nums, target));
		res.push_back(findMostRight(nums, target));

		return res;
    }
};

void unit_test() {
	Solution s;

	vector<int> nums = {5,7,7,8,8,10};
	auto res = s.searchRange(nums, 8);
	for (auto num : res) {
		cout << num << " ";
	}
	cout << endl;
}

int main() {
	unit_test();
	return 0;
}
