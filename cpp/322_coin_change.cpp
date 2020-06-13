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

// 给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
// [1, 2, 5] 11 => 11 = 5 + 5 + 1
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
		vector<int> dp(amount+1, INT_MAX);
		dp[0] = 0;

		for (int coin: coins) {
			for (int i = coin; i <= amount; ++i) {
				if (dp[i-coin] != INT_MAX) {
					dp[i] = min(dp[i], dp[i-coin]+1);
				}
			}
		}

		return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
