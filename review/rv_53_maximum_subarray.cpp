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
	// 归并的思路
	int helper(vector<int>& nums, int l, int r) {
		if (l == r) {
			return nums[l];
		}
		int mid = l + (r - l) / 2;
		int leftSum = helper(nums, l, mid);
		int rightSum = helper(nums, mid+1, r);

		int leftSuffixSum = nums[mid];
		int leftSuffixMax = nums[mid];
		for (int i = mid-1; i >= l; --i) {
			leftSuffixSum += nums[i];
			leftSuffixMax = max(leftSuffixMax, leftSuffixSum);
		}
		int rightPrefixSum = nums[mid+1];
		int rightPrefixMax = nums[mid+1];
		for (int i = mid+2; i <= r; ++i) {
			rightPrefixSum += nums[i];
			rightPrefixMax = max(rightPrefixMax, rightPrefixSum);
		}
		int rangeSum = leftSuffixMax + rightPrefixMax;
		return max(rangeSum, max(leftSum, rightSum));
	}

	int maxSubArray(vector<int>& nums) {
		int nsize = nums.size();
		if (nsize == 0) { return 0; }
		if (nsize == 1) { return nums[0]; }

		int l = 0, r = nsize -1;
		return helper(nums, l, r);
	}
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
};
