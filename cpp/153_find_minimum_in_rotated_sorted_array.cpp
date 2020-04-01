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

// 给定被旋转的一个有序数组，也就是数组中存在两段有序，让我们找到最小值；PS：数组中的元素没有重复；
// 使用二分，每次找到mid后判断左右两边是否存在不是有序，如果存在，则去不是有序的一边，最小的值一定是在非有序这边。
// 直到只要两个元素，此时左右都有序，返回其中较小的即可。
// 如果nums只要一个元素，那么不会进行二分，直接返回nums[left]或者nums[right]
class Solution {
public:
    int findMin(vector<int>& nums) {
		if (nums.empty()) { return -1; }
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = left + (right - left) / 2;
			if (nums[left] > nums[mid]) {
				right = mid;
			} else if (nums[mid+1] > nums[right]) {
				left = mid+1;
			} else {
				return min(nums[left], nums[mid+1]);
			}
		}
		return nums[right];
    }
};
