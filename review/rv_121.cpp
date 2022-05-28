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
	int maxProfit(vector<int>& prices) {
		int nsize = prices.size();
		if (nsize < 2) { return 0; }

		int res = 0;
		vector<vector<int>> dp(nsize, vector<int>(2, 0));
		dp[0][0] = 0; dp[0][1] = -prices[0];

		for(int i = 1; i < nsize; ++i) {
			dp[i][0] = max(dp[i-1][0], prices[i]+dp[i-1][1]);
			dp[i][1] = max(dp[i-1][1], -prices[i]);
			res = max(res, dp[i][0]);
		}
		return res;
	}
	int maxProfit(vector<int>& prices) {
		int nsize = prices.size();
		if (nsize < 2) { return 0; }

		int l = 0, r = 1;
		int res = 0;
		while (r < nsize) {
			if (prices[l] > prices[r]) {
				l = r;
			} else {
				res = max(res, prices[r] - prices[l]);
			}
			++r;
		}

		return res;
	}
};
