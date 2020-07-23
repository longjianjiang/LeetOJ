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

// 返回数组的连续和等于k的个数；


// 1> 暴力；
// 2> 前缀和，空间换时间；
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
		vector<int> prefix;

		int sum = 0, res = 0;
		for (auto num: nums) {
			sum += num;
			prefix.push_back(sum);
		}

		unordered_map<int, int> dict;
		for (int i = 0; i < nums.size(); ++i) {
			int prefixSum = prefix[i];
			if (prefixSum == k) { ++res; }

			// prefix[i] - prefix[j] == k
			// find prefix[j] == prefix[i] - k
			int diff = prefixSum-k;
			if (dict.find(diff) != dict.end()) { res += dict[diff]; }
			dict[prefixSum] += 1;
		}
		return res;
    }
};
