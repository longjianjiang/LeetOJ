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

// 给定rotated sorted array，数组中可能存在重复元素，要求寻找到最小值返回；
// 1 7 7 7 7
// 7 1 7 7 7
// 1> 从左右开始遍历，找到逆序的返回，不过首先需要过滤掉重复元素；
class Solution {
public:
    int findMin(vector<int>& nums) {
		if (nums.empty()) { return -1; }
		// sorted array
		if (nums.size() == 1 || (nums[0] < nums[nums.size()-1])) { return nums[0]; }

		int left = 0, right = nums.size()-1;
		while (left <= right) {
			while (left < right && nums[left+1] == nums[left]) { ++left; }
			if (left == right) { return nums[left]; }
			if (nums[left+1] < nums[left]) { return nums[left+1]; }

			while (right > left && nums[right-1] == nums[right]) { --right; }
			if (left == right) { return nums[left]; }
			if (nums[right-1] > nums[right]) { return nums[right]; }

			++left; --right;
		}

		return -1;
    }
};
