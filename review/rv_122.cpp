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

// dp[i] 某天的收益；
// dp[i][0] 空仓收益，dp[i][1] 满仓收益；
// 空仓收益 = max(继续空仓，满仓卖出空仓);
// 满仓收益 = max(继续满仓，空仓买入满仓);
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int nsize = prices.size();
		if (nsize < 2) { return 0; }

		int res = 0;
		vector<vector<int>> dp(nsize, vector<int>(2, 0));
		dp[0][0] = 0; dp[0][1] = -prices[0];
		for (int i = 1; i < nsize; ++i) {
			dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
			dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
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
				if (r+1 < nsize && prices[r+1] < prices[r]) {
					res += prices[r] - prices[l];
					l = r;
				}
			}
			++r;
		}
		// [7, 1, 5, 3, 6, 4]
		// [1, 2, 3, 4]
		res += prices[r-1] - prices[l];

		return res;
    }
};

void unit_test() {
	Solution s;

	vector<int> arr1 = {7, 1, 5, 3, 6, 4};
	vector<int> arr2 = {1, 2, 3, 4};

	cout << s.maxProfit(arr1) << endl;
	cout << s.maxProfit(arr2) << endl;
}

int main() {
	unit_test();
	return 0;
}
