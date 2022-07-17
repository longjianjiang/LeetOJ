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
给定一个二进制数组 nums , 找到含有相同数量的 0 和 1 的最长连续子数组，并返回该子数组的长度。

输入: nums = [0,1]
输出: 2
说明: [0, 1] 是具有相同数量 0 和 1 的最长连续子数组。
*/

class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		int nsize = nums.size();
		if (nsize < 2) { return 0; }

		vector<int> prefix(nsize+1, 0);
		for (int i = 0; i < nsize; ++i) {
			int num = nums[i] == 0 ? -1 : 1;
			prefix[i+1] = prefix[i] + num;
		}

		unordered_map<int, int> dict;
		dict[0] = -1;
		int res = 0;
		// [0, 1, 0]
		// [-1, 0, -1]
		// [0, 0, 1, 1]
		// [-1, -2, -1, 0]
		for (int i = 0; i < nsize; ++i) {
			int sum = prefix[i+1];
			if (dict.find(sum) != dict.end()) {
				int len = i - dict[sum];
				res = max(res, len);
			} else {
				dict[sum] = i;
			}
		}
		return res;

	}
    int findMaxLength2(vector<int>& nums) {
		unordered_map<int, int> dict;
		int res = 0;
		for (int i = 0; i < nsize; ++i) {
			int sum = prefix[i+1];
			if (i > 0 && i % 2 == 0) {
				res = max(res, i + 1);
			}
			int remainder = sum % 2;
			if (dict.find(remainder) != dict.end()) {
				res = max(res, i - dict[remainder] + 1);
			} else {
				dict[remainder] = i;
			}
		}

		return res;
	}
	// 暴力
    int findMaxLength(vector<int>& nums) {
		int nsize = nums.size();
		if (nsize < 2) { return 0; }

		int res = 0;
		// [0, 1, 0]
		for (int i = 0; i < nsize; ++i) {
			for (int j = i+1; j < nsize; ++j) {
				int len = j - i + 1;
				if (len % 2 == 0) {
					int cnt = 0;
					for (int p = i; p <= j; ++p) {
						if (nums[p] == 0) {
							cnt -= 1;
						} else {
							cnt += 1;
						}
					}
					if (cnt == 0) {
						res = max(res, len);
					}
				}
			}
		}
		return res;
    }
};

void unit_test() {
	Solution s;

	vector<int> nums1 = {0, 1, 0};
	vector<int> nums2 = {0, 0, 1, 1};

	cout << s.findMaxLength(nums1) << endl;
	cout << s.findMaxLength(nums2) << endl;
}

int main() {
	unit_test();
	return 0;
}
