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
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。
*/

// 1> sliding window
class Solution {
public:
	int bs(vector<int>& prefix, int l, int r, int target) { 
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (prefix[mid] >= target) {
				if (mid == 0 || prefix[mid-1] < target) {
					return mid;
				} else {
					r = mid - 1;
				}
			} else {
				l = mid + 1;
			}
		}
		return -1;
	}

	int minSubArrayLen(int target, vector<int>& nums) {
		int nsize = nums.size();
		if (nsize == 0) { return 0; }

		vector<int> prefix(nsize+1, 0);
		for (int i = 0; i < nsize; ++i) {
			int num = nums[i];
			if (num >= target) { return 1; }
			prefix[i+1] = prefix[i] + num;
		}
		int res = nsize + 1;
		for (int i = 0; i < nsize; ++i) {
			int pos = bs(prefix, i+1, nsize, prefix[i]+target);
			if (pos == -1) { continue; }
			res = min(res, pos - i);
		}
		return res > nsize ? 0 : res;
	}

	int minSubArrayLen2(int target, vector<int>& nums) {
		int nsize = nums.size();
		if (nsize == 0) { return 0; }

		int l = 0, r = 0;
		int res = nsize + 1;
		int sum = 0;
		// [2, 3, 1, 2, 4, 3]
		while (r < nsize) {
			sum += nums[r++];
			while (sum >= target) {
				res = min(res, r - l);
				sum -= nums[l++];
			}
		}

		return res > nsize ? 0 : res;
	}
    int minSubArrayLen1(int target, vector<int>& nums) {
    	int nsize = nums.size();
		if (nsize == 0) { return 0; }

		int l = 0, r = 0;
		int res = nsize + 1;
		int sum = 0;
		while (r < nsize) { sum += nums[r];
			if (sum >= target) {
				res = min(res, r-l+1);
				do {
					sum -= nums[l];
					++l;
					if (sum >= target) {
						res = min(res, r-l+1);
					}
				} while (sum - nums[l] >= target);
			} 
			++r;
		}

		return res > nsize ? 0 : res;
    }
	int minSubArrayLen3(int target, vector<int>& nums) {
		int nsize = nums.size();
		
		int l = 0, r = 0;
		int res = nsize + 1;
		int sum = 0;
		while (r < nsize) {
			sum += nums[r];
			if (sum >= target) {
				do {
					int len = r - l + 1;
					res = min(res, len);
					sum -= nums[l++];
				} while (sum >= target);
			}
			++r;
		}
		return res > nsize ? 0 : res;
	}
	int bs2(vector<int>& prefix, int l, int r, int target) {

	}
	// [   2, 3, 1, 2, 4, 3]
	// [0, 2, 5, 6, 8, 12, 15]
	int minSubArrayLen4(int target, vector<int>& nums) {
		int nsize = nums.size();
		if (nsize == 0) { return nsize; }

		vector<int> prefix(nsize+1, 0);
		for (int i = 0; i < nsize; ++i) {
			int tmp = nums[i];
			if (tmp >= target) { return 1; }
			prefix[i+1] = prefix[i] + tmp;
		}
		int res = nsize + 1;
		for (int i = 0; i < nsize; ++i) {
			int pos = bs(prefix, i+1, nsize, prefix[i]+target);
			if (pos == -1) { continue; }
			res = min(res, pos - i);
		}
		return res > nsize ? 0 : res;
	}
};

void unit_test() {
	Solution s;

	vector<int> arr1 = {2, 3, 1, 2, 4, 3};
	cout << s.minSubArrayLen(7, arr1) << endl;
}

int main() {
	unit_test();
	return 0;
}
