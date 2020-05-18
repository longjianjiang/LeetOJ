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

// 从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

// 1> 排序；
// 2> 不排序；遍历一次，取最大值和最小值（不包括0），计算diff，小于5则有序；
class Solution {
public:
    bool isStraight(vector<int>& nums) {
		int nsize = nums.size();
		sort(nums.begin(), nums.end());
		int zeroCnt = 0, idx = 0;
		while (nums[idx] == 0) {
			++idx;
			++zeroCnt;
		}
		int cnt = 0;
		while (idx < nsize-1) {
			int diff = nums[idx+1] - nums[idx];
			if (diff == 0) { return false; }
			cnt += (diff-1);
			++idx;
		}
		return cnt <= zeroCnt;
    }
	
	bool isStraight_2(vector<int>& nums) {
		int nsize = nums.size();
		unordered_map<int, int> dict;

		int max = INT_MIN;
		int min = INT_MAX;
		for (int i = 0; i < nsize; ++i) {
			int num = nums[i];
			if (num == 0) { continue; }
			dict[num]++;
			if (dict[num] > 1) { return false; }
			if (num > max) { max = num; }
			if (num < min) { min = num; }
		}
		if (dict[0] >= 4) { return true; }
		int diff = max - min;
		return diff < 5;
	}
};
