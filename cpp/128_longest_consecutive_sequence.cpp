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
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		unordered_set<int> us;
		for (auto num : nums) {
			us.insert(num);
		}

		int res = 0;
		for (auto num : nums) {
			if (us.find(num - 1) == us.end()) {
				int first = num;
				int cnt = 1;
				while (us.find(first + 1) != us.end()) {
					++first;
					++cnt;
				}
				res = max(res, cnt);
			}
		}

		return res;
    }
};
