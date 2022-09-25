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

// 给定数组，返回数组中最大的数字索引，该数组大于左右两边的数字。
// 如果存在多个峰值，返回其中任意一个。
/*
输入：nums = [1,2,1,3,5,6,4]
输出：1 或 5
解释：你的函数可以返回索引 1，其峰值元素为 2；
     或者返回索引 5， 其峰值元素为 6。
 */
class Solution {
public:
	int findPeakElement(vector<int>& nums) {
		int nsize = nums.size();
		int l = 0, r = nsize - 1;

		while (l < r) {
			int mid = l + (r - l) / 2;
			// mid+1 always valid, when mid is zero, mid-1 invalid.
			if (nums[mid] < nums[mid+1]) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		return l;
	}
    int findPeakElement(vector<int>& nums) {
		int nsize = nums.size();
		int l = 0, r = nsize - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (mid + 1 == nsize || mid - 1 < 0) { break; }
			if (nums[mid] > max(nums[mid+1], nums[mid-1])) {
				return mid;
			}
			if (nums[mid-1] > nums[mid+1]) {
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		// case [0, 1] fail.
		return l;
    }

};
