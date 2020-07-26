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

// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
// 你可以假设数组中无重复元素。

// 二分即可；
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		int l = 0, r = nums.size()-1;
		while (l <= r) {
			int mid = l + (r-l)/2;
			if (nums[mid] == target) {
				return mid;
			} else if (nums[mid] < target) {
				l = mid+1;
			} else {
				r = mid-1;
			}
		}
		// 此时l的index大于target，直接返回
		return l;
    }
};
