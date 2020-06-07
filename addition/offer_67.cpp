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

// 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

// dp; 自上而下分析问题；自下而上求解问题，这样可以避免重复计算；
class Solution {
public:
    int cuttingRope(int n) {
		if (n < 2) { return 0; }

		vector<int> dp(n+1, 1);
		for (int i = 3; i <= n; ++i) {
			for (int j = 1; j <= i/2; ++j) {
				dp[i] = max(dp[i], max(j * (i-j), j * dp[i-j]));
			}
		}

		return dp[n];
    }
};
