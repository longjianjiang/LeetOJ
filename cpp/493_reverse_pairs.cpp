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

// 给定一个数组 nums ，如果 i < j 且 nums[i] > 2*nums[j] 我们就将 (i, j) 称作一个重要翻转对。
// 你需要返回给定数组中的重要翻转对的数量。

class Solution {
public:
	int helper(vector<int>& nums, int left, int right) {
		if (left >= right) { return 0; }

		int mid = left + (right - left) / 2;
		int cnt = helper(nums, left, mid) + helper(nums, mid+1, right);
		int added = 0;

		for (int i = left; i <= mid; ++i) {
			for (int j = mid+added+1; j <= right; ++j) { // j 开始需要添加added，合并的时候前后两段都是有序的。
				if((long)nums[i] > (long)2*nums[j]) {
					added += 1;
				} else {
					break;
				}
			}
			cnt += added;
		}

        inplace_merge(nums.begin()+left, nums.begin()+mid+1, nums.begin()+right+1);
		//sort(nums.begin()+left, nums.begin()+right+1); // 使用sort时间会更慢

        return cnt;
	}

    int reversePairs(vector<int>& nums) {
		int left = 0, right = nums.size()-1;
		return helper(nums, left, right);
    }
};
