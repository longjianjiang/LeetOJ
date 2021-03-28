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
 * 从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。
输入: [0,0,1,2,5]
        0 1 1 3
输出: True
*/


class Solution {
public:
    bool isStraight(vector<int>& nums) {
		int nsize = nums.size();

		unordered_map<int, int> dict;
		int min = INT_MAX, max = INT_MIN;
		for (int i = 0; i < nsize; ++i) {
			int num = nums[i];

			if (num == 0) { continue; }

			dict[num] += 1;
			if (dict[num] > 1) { return false; }
			if (num > max) { max = num; }
			if (num < min) { min = num; }
		}

		int diff = max - min;
		return diff < 5;
    }
};
