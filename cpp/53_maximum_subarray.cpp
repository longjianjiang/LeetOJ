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

// 归并的方式来写，先拆，当只有两个元素的时候，此时有三种可能性，一种是left，一种是right，另一种是left+right。
// 接下来其实就是求左半部分后缀和最大的，右半部分前缀和最大的，两个加起来分别和整个left和整个right比较，得到最大的
class Solution {
public:
	int helper(vector<int>& nums, int left, int right) {
		if (left == right) { return nums[left]; }

		int mid = left + (right-left)/2;
		int left_sum = helper(nums, left, mid);
		int right_sum = helper(nums, mid+1, right);

		// calculate left suffix sum
		int left_suffix_tmp = nums[mid], left_suffix_sum = nums[mid];
		int i = mid-1;
		while (i >= left) {
			left_suffix_tmp += nums[i--];
			left_suffix_sum = max(left_suffix_tmp, left_suffix_sum);
		}

		// calculate right prefix sum
		int right_prefix_tmp = nums[mid+1], right_prefix_sum = nums[mid+1];
		i = mid+2;
		while (i <= right) {
			right_prefix_tmp += nums[i++];
			right_prefix_sum = max(right_prefix_tmp, right_prefix_sum);
		}

		int range_sum = left_suffix_sum + right_prefix_sum;
		return max(range_sum, max(left_sum, right_sum));
	}

    int maxSubArray(vector<int>& nums) {
		if (nums.empty()) { return 0; }
		if (nums.size() == 1) { return nums[0]; }

		int left = 0, right = (int)(nums.size()-1);
		return helper(nums, left, right);
    }

	// dp[0] = nums[0]
	// dp[i] = max(nums[i], nums[i]+dp[i-1])
	int maxSubArray_dp(vector<int>& nums) {
		if (nums.empty()) { return 0; }
		if (nums.size() == 1) { return nums[0]; }
		
		int dp_sum = nums[0], max_sum = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			dp_sum = max(nums[i], nums[i]+dp_sum);
			max_sum = max(dp_sum, max_sum);
		}

		return max_sum;
	}
};

void unit_test() {
	Solution s;

	vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	cout << s.maxSubArray(nums) << endl;
}

int main() {
	unit_test();

	return 0;
}
