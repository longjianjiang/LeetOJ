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
 * 数组中占比超过一半的元素称之为主要元素。给你一个 整数 数组，找出其中的主要元素。若没有，返回 -1 。请设计时间复杂度为 O(N) 、空间复杂度为 O(1) 的解决方案。

 输入：[1,2,5,9,5,9,5,5,5]
 输出：5
 */

//
class Solution {
public:
    int majorityElement(vector<int>& nums) {
		if (nums.empty()) { return -1; }
		
		int nsize = nums.size(), half = nsize / 2;
		int res = 0;
		for (int i = 0; i < 32; ++i) {
		    int ones = 0, zeros = 0;
			int mask = 1 << i;
			for (int i = 0; i < nsize; ++i) {
				if (ones > half || zeros > half) { break; }
				if (nums[i] & mask) {
					ones++;
				} else {
					zeros++;
				}
			}
			if (ones > zeros) { res |= mask; }
		}

		int cnt = 0;
		for (int i = 0; i < nsize; ++i) {
			if (res == nums[i]) { ++cnt; }
		}

		return cnt > half ? res : -1;
    }

	// 每次从数组中去掉两个不同的元素，最后剩余的元素就是主要元素或者是最后剩余的元素。结束后遍历一次数组，判断是否为主要元素。
	int majorityElement(vector<int>& nums) {
		int nsize = nums.size();
		if (nsize < 1) { return -1; }

		int res = nums[0];
		int cnt = 1;
		for (int i = 1; i < nsize; ++i) {
			if (cnt == 0) {
				res = nums[i];
				cnt = 1;
			} else if (nums[i] == res) {
				++cnt;
			} else {
				--cnt;
			}
		}
		if (cnt > 0) {
			int tmp = 0;
			for (auto num: nums) {
				if (num == res) { ++tmp; }
				if (tmp > nsize / 2) { return res; }
			}
		}
		return -1;
	}
};

void unit_test() {
	Solution s;
	vector<int> v1 = {1,2,5,9,5,9,5,5,5};
	vector<int> v2 = {1, 2};
	vector<int> v3 = {2,2,1,1,1,2,2};
	cout << s.majorityElement(v1) << endl;
	cout << s.majorityElement(v2) << endl;
	cout << s.majorityElement(v3) << endl;
}

int main() {
	unit_test();
	return 0;
}
