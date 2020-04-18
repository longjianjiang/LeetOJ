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

// 跳台阶，可以跳1-n阶，问到n阶有多少种方法；
// dp[0] = 1; dp[1] = 1; dp[2] = 2; 
// dp[3] = dp[1] + dp[2] + 1 = 4;
// dp[4] = dp[3] + dp[2] + dp[1] + 1 = 8;
// dp[4] - dp[3] = dp[3] => dp[4] = 2*dp[3]
class Solution {
public:
    int jumpFloorII(int number) {
		vector<int> dp(number+1, 1);
		dp[1] = 1; dp[2] = 2;
		for (int i = 3; i <= number; ++i) {
			dp[i] = 2*dp[i-1];
		}
		return dp[number];
    }
};
