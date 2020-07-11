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

// 硬币。给定数量不限的硬币，币值为25分、10分、5分和1分，编写代码计算n分有几种表示法。(结果可能会很大，你需要将结果模上1000000007)

class Solution {
public:
    int waysToChange(int n) {
		vector<int> coins = {1, 5, 10, 25};

		vector<int> dp(n+1, 0); 
		dp[0] = 1;
		for (int coin: coins) {
			for (int i = coin; i <= n; ++i) {
				dp[i] = (dp[i]+dp[i-coin]) % 1000000007;
			}
		}

		return dp[n];
    }
};


void unit_test() {
	Solution s;

	cout << s.waysToChange(5) << endl;
	cout << s.waysToChange(10) << endl;
}

int main() {
	unit_test();
	return 0;
}

// dp[1] = 0
// dp[2] = 1

for (int i = 3; i <= n; ++i) {
	for (int j = 1; j < i/2; ++j) {
		dp[i] = max(dp[i-j]*j, (i-j)*dp[j]);
	}
}
// dp[3] = max()