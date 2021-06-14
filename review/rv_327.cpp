/*
输入：nums = [-2,5,-1], lower = -2, upper = 2
输出：3
解释：存在三个区间：[0,0]、[2,2] 和 [0,2] ，对应的区间和分别是：-2 、-1 、2 。
*/

class Solution {
public:
    int helper(vector<long>& sum, int lower, int upper, int left, int right) {
        if (left >= right) { return 0; }

        int mid = left + (right - left) / 2;
        int cnt = helper(sum, lower, upper, left, mid) + helper(sum, lower, upper, mid+1, right);
        int m = mid + 1, n = mid + 1;

        // [lower, upper]
        for (int i = left; i <= mid; ++i) {
            while (m <= right && sum[m] - sum[i] < lower) { ++m; }
            while (n <= right && sum[n] - sum[i] <= upper) { ++n; }
            cnt += (n - m);
        }

        inplace_merge(sum.begin()+left, sum.begin()+mid+1, sum.begin()+right+1);
        return cnt;
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int nsize = nums.size();
        vector<long> sum(nsize+1, 0);
        for (int i = 0; i < nsize; ++i) { sum[i+1] = sum[i] + nums[i]; }
        
        return helper(sum, lower, upper, 0, nsize);
    }
};
