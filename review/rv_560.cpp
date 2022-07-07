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
		int nsize = nums.size();
        if (nsize == 0) { return 0; }

        vector<int> prefix(nsize+1, 0);
        for (int i = 0; i < nsize; ++i) {
            prefix[i+1] = prefix[i] + nums[i];
        }

        int res = 0;
        unordered_map<int, int> dict;
        for (int i = 0; i < nsize; ++i) {
            int prefixSum = prefix[i+1];
            if (prefixSum == k) { ++res; }

            int diff = prefixSum - k;
            if (dict.find(diff) != dict.end()) { res += dict[diff]; }
            dict[prefixSum] += 1;
        }

        return res;
    }
};
