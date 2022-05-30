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

// 和121，122类似，交易次数最多两次；
// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6

// dp[i] 某天的收益；
// dp[i][0] 空仓收益，dp[i][1] 满仓收益；
// 空仓收益 = max(继续空仓，满仓卖出空仓);
// 满仓收益 = max(继续满仓，空仓买入满仓);

class Solution {
public:
	// [ref](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/solution/by-larrychen__-1iko/)
	int maxProfit(vector<int>& prices) {
		int nsize = prices.size();
		if (nsize < 2) { return 0; }

		int k = 2;
		vector<vector<vector<int>>> dp(nsize+1, vector<vector<int>>(k+1, vector<int>(2, 0)));

		for (int j = 1; j <= k; ++j) {
			dp[0][j][0] = 0; 
			dp[0][j][1] = INT_MIN;
		}

		for (int i = 1; i <= nsize; ++i) {
			for (int j = 1; j <= k; ++j) {
				dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i-1]);
				dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i-1]);
			}
		}
		return dp[nsize][k][0];
	}

    int maxProfit_tp(vector<int>& prices) {
		int nsize = prices.size();
		if (nsize == 0) { return 0; }

		vector<int> left(nsize, 0);
		vector<int> right(nsize, 0);

		calLeft(prices, left); 
        calRight(prices, right);

		int res = 0;
		for (int i = 0; i < nsize; ++i) {
			res = max(res, left[i] + right[i]);
		}
		return res;
    }
};

void unit_test() {
	Solution s;

	vector<int> list = {3, 3, 5, 0, 0, 3, 1, 4};
	int res = s.maxProfit_tp(list);
	cout << res << endl;
}

int main() {
	unit_test();
	return 0;
}
