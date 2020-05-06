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

// 给一个数组，返回它的最大连续子序列的和;
// [6,-3,-2,7,-15,1,2,2]

// 1> 暴力，两层循环；
// 2> dp, dp[0] = nums[0]; dp[i] = max(nums[i], nums[i]+dp[i-1]);
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.empty()) { return 0; }
		if (array.size() == 1) { return array[0]; }

		int dpSum = array[0], maxSum = array[0];
		for (int i = 1; i < array.size(); ++i) {
			dpSum = max(array[i], array[i]+dpSum);
			maxSum = max(dpSum, maxSum);
		}

		return maxSum;
    }
};
