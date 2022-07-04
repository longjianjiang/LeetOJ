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
    int minSubArrayLen(int target, vector<int>& nums) {
    	int nsize = nums.size();
		if (nsize == 0) { return 0; }

		int l = 0, r = 0;
		int res = nsize + 1;
		int sum = 0;
		while (r < nsize) {
			sum += nums[r];
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
