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

/*
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
*/

// 首先数组排序，两层循环，然后就是two sum的问题。注意需要过滤重复元素；
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> res;
		int nsize = nums.size();
		if (nsize == 0) { return res; }
		
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nsize; ++i) {
			int num_1 = nums[i];
			for (int j = i+1; j < nsize; ++j) {
				int num_2 = nums[j];
				// two sum
				int left = j+1; int right = nsize-1;
				while (left < right) {
					int sum = num_1 + num_2 + nums[left] + nums[right];
					if (sum < target) {
						++left;
					} else if (sum > target) {
						--right;
					} else {
						vector<int> item = {num_1, num_2, nums[left], nums[right]};
						res.push_back(item);
						do { ++left; } while (left < right && nums[left] == nums[left-1]);
						do { --right; } while (left < right && nums[right] == nums[right+1]);
					}
				}
				while (j < nsize-1 && nums[j] == nums[j+1]) { ++j; }
			}
			while (i < nsize-1 && nums[i] == nums[i+1]) { ++i; }
		}

		return res;
    }
};
