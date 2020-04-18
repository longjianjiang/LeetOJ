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

// 台阶，一次可以一阶或者两阶，给出走到n阶一共的走法；
// dp[0] = 0; dp[1] = 1; dp[2] = 2; dp[i] = dp[i-1] + dp[i-2]
class Solution {
public:
    int jumpFloor(int number) {
		vector<int> dp(number+1, 0);
		dp[1] = 1; dp[2] = 2;
		for (int i = 3; i <= number; ++i) {
			dp[i] = dp[i-1] + dp[i-2];
		}
		return dp[number];
    }
};
