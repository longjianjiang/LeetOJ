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

// 给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。

// dp[i] 代表使用coins凑成金额i的组合数；dp[0] = 1; 
// dp[i] = dp[i] + dp[i-coin];
// 首先遍历coins，从coin到i，依次进行累计不同的组合数。
class Solution {
public:
    int change(int amount, vector<int>& coins) {
		vector<int> dp(amount+1, 0);
		dp[0] = 1;

		for (int coin: coins) {
			for (int i = coin; i <= n; ++i) {
				dp[i] = dp[i] + dp[i-coin];
			}
		}

		return dp[amount];
    }
};

