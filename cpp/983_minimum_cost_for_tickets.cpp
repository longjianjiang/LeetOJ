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

/*
输入：days = [1,4,6,7,8,20], costs = [2,7,15]
输出：11
解释：
例如，这里有一种购买通行证的方法，可以让你完成你的旅行计划：
在第 1 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 1 天生效。
在第 3 天，你花了 costs[1] = $7 买了一张为期 7 天的通行证，它将在第 3, 4, ..., 9 天生效。
在第 20 天，你花了 costs[0] = $2 买了一张为期 1 天的通行证，它将在第 20 天生效。
你总共花了 $11，并完成了你计划的每一天旅行。
*/

// dp[i] 表示第i天花费最少的钱；
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
		int nsize = days.size();
		int lastDay = days[nsize-1];
		
		vector<int> dp(lastDay+1, 0);
		int pos = 0;
		for (int i = 1; i <= lastDay; ++i) {
			if (i == days[pos]) {
				int one = i-1;
				int two = i-7 > 0 ? i-7 : 0;
				int three = i-30 > 0 ? i-30 : 0;
				dp[i] = min(dp[one] + costs[0], min(dp[two]+costs[1], dp[three]+costs[2]));
				++pos;
			} else {
				dp[i] = dp[i-1];
			}
		}

		return dp[lastDay]; 
    }
};
