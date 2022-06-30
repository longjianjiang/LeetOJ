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

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int nsize = nums.size();

        int sum = nums[0];
        int res = sum;
        for (int i = 1; i < nsize; ++i) {
			// 连续range最大
            sum = max(nums[i], sum + nums[i]);
			// 总的最大
            res = max(res, sum);
        }
        return res;
    }

	int helper(vector<int>& nums, int left, int right) {
		if (left == right) { return nums[left]; }
		
		int mid = left + (right - left) / 2;
		int leftSum = helper(nums, left, mid);
		int rightSum = helper(nums, mid+1, right);

		int leftSuffixMax = nums[mid];
		int leftSuffixSum = leftSuffixMax;
		for (int i = mid-1; i >= left; --i) {
			leftSuffixSum += nums[i];
			leftSuffixMax = max(leftSuffixSum, leftSuffixMax);
		}

		int rightPrefixMax = nums[mid+1];
		int rightPrefixSum = rightPrefixMax;
		for (int i = mid+2; i <= right; ++i) {
			rightPrefixSum += nums[i];
			rightPrefixMax = max(rightPrefixSum, rightPrefixMax);
		}

		int rangeSum = leftSuffixMax + rightPrefixMax;
		return max(rangeSum, max(leftSum, rightSum));
	}

	int maxSubArray(vector<int>& nums) {
		int nsize = nums.size();
		if (nsize == 0) { return 0; }
		if (nsize == 1) { return nums[0]; }

		return helper(nums, 0, nsize-1);
	}
};
