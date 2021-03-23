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
 给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
 
 输入:nums = [1,1,1], k = 2
 输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
		if (nums.empty()) { return 0; }
		int nsize = nums.size();

		vector<int> prefix;
		int sum = 0;
		for (int i = 0; i < nsize; ++i) {
			sum += nums[i];
			prefix.push_back(sum);
		}
		int res = 0;
		unordered_map<int, int> dict;
		for (int i = 0; i < nsize; ++i) {
			int prefixSum = prefix[i];
			if (prefixSum == k) { ++res; }

			int diff = prefixSum - k;
			if (dict.count(diff)) { res += dict[diff]; }
			dict[prefixSum] += 1;
		}

		return res;
    }
};
