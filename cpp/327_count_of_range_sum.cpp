#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 给定数组和一个范围，要求返回数组所有可能的range处于给定范围的个数；
// 最简单的办法两层for循环即可；
// 更高效的是使用的分治的思想；
// 1> sum数组，存放[0, i]的和，这里idx从1开始存放，这样求range(i, j)的时候，直接sum[j+1]-sum[i]就可以了；
// 2> 类似归并排序，合并的时候，左右两边，遍历左边，去右边去查找一个range(m, n)加上左边某个元素处于要求中，cnt加n-m;
// 3> 将[left, right)这区间进行排序；
class Solution {
public:
	int helper(vector<long>& sum, int lower, int upper, int left, int right) {
		if (right - left <= 1) { return 0; }
		int mid = left + (right - left) / 2;
		int m = mid, n = mid;
		int cnt = helper(sum, lower, upper, left, mid) + helper(sum, lower, upper, mid, right);

		for (int i = left; i < mid; ++i) {
			while (m < right && sum[m] - sum[i] <  lower) { ++m; }
			while (n < right && sum[n] - sum[i] <= upper) { ++n; }
			cnt += (n-m);
		}
		inplace_merge(sum.begin()+left, sum.begin()+mid, sum.begin()+right);
		return cnt;
	}

	// [-2, 5, -1] => [0, -2, 3, 2]
    int countRangeSum(vector<int>& nums, int lower, int upper) {
		int len = nums.size();
		vector<long> sum(len+1, 0);
		for (int i = 0; i < len; ++i) { sum[i+1] = sum[i] + nums[i]; }
		return helper(sum, lower, upper, 0, len+1);
    }
};
