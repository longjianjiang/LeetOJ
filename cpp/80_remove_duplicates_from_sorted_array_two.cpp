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

// 给定有序数组，删除重复的数字，最多重复次数为2，返回个数
// 遍历，给数组重新赋值，因为允许重复一次，所以增加一个距离判断，当不等时更新这个距离索引。

class Solution {
public:
	int removeDuplicates(vector<int>& nums, int repeat_cnt) {
		int nsize = (int)nums.size();
		if (nsize <= repeat_cnt) { return nsize; }

		int cnt = repeat_cnt;
		for (int i = repeat_cnt; i < nsize; ++i) {
			if (nums[i] != nums[cnt-repeat_cnt]) {
				nums[cnt++] = nums[i];
			}
		}

		return cnt;
	}

    int removeDuplicates(vector<int>& nums) {
		return removeDuplicates(nums, 2);

		int nsize = (int)nums.size();
		if (nsize <= 2) { return nsize; }

		int cursor = 0, cnt = 0, left = 0;
		while (cursor < nsize) {
			int num = nums[cursor++];

			while (cursor < nsize && cursor-left > 1 && nums[cursor] == num) { ++cursor; }

			if (cursor < nsize && nums[cursor] != num) { left = cursor; }
			nums[cnt++] = num;
		}

		return cnt;
    }
};


