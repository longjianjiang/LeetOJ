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

// Input: [7,1,5,3,6,4]
// Output: 7
// 和121类似，区别在于可以进行多笔交易；
class Solution {
public:
	int maxProfit_dp(vector<int>& prices) {
		int nsize = prices.size();
		if (nsize < 2) { return 0; }

		int res = 0;
		vector<vector<int>> dp(nsize, vector<int>(2, 0));
		dp[0][0] = 0; dp[0][1] = -prices[0];

		for (int i = 1; i < nsize; ++i) {
			dp[i][0] = max(dp[i-1][0], prices[i] + dp[i-1][1]);
			dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
		}
		return res;
	}

	int maxProfit_sw(vector<int>& prices) {
		int nsize = prices.size();
		if (nsize < 2) { return 0; }

		int res = 0;
		int l = 0, r = 1;

		while (r < nsize) {
			if (prices[r] > prices[l]) {
				if (r+1 < nsize && prices[r+1] < prices[r]) {
					res += prices[r] - prices[l];
					l = r;
				}
			} else {
				l = r;
			}
			++r;
		}
		// case: [1, 2, 3, 4]
		res += prices[r-1] - prices[l];

		return res;
	}
};
