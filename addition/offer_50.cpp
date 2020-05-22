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

// 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

// 1> sort; 排序后寻找前后一样的；
// 2> dict; cnt 大于1，返回重复的;
// 3> swap; 如果不重复nums[i] == i，如果不等于，进行swap，如果nums[i] == nums[nums[i]] 则返回相同的；

// [0, 1, 2, 3, 4]
// [1, 2, 3, 2, 4]
// [2, 1, 3, 2, 4]
// [3, 1, 2, 2, 4]
// [2, 1, 2, 3, 4]
// return 2
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
		for (int i = 0; i < nums.size(); ++i) {
			while (nums[i] != i) {
				if (nums[i] == nums[nums[i]]) { return nums[i]; }
				int tmp = nums[i];
				nums[i] = nums[nums[i]];
				nums[tmp] = tmp;
			}
		}

		return -1;
    }
};
