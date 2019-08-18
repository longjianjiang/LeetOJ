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

// p含有`.`, `*`，分别表示任意一个字符，和任意0个或多个前面的字符。判断s和p是否匹配。
class Solution {
public:
    bool isMatch(string s, string p) {
		if (p.empty()) { return s.empty(); }

		bool first_match = s.size() > 1 && (p[0]==s[0] || p[0]=='.');

		if (p.size() == 1) { return s.size() == 1 && first_match; }

		if (p[1] != '*') {
			return first_match && isMatch(s.substr(1), p.substr(1));
		} else {
			bool one = isMatch(s, p.substr(2));
			bool two = first_match && isMatch(s.substr(1), p);
			return one || two;
		}
    }

	bool isMatch_dp(string s, string p) {
		int m = (int)s.size(), n = (int)p.size();
		vector<vector<bool>> dp(m+1, vector(n+1, false));
		dp[0][0] = true;

		for (int i = 1; i <= n; ++i) {
			dp[0][i] = (i>1) && (p[i-1] == '*') && dp[0][i-2];
		}

		for (int i = 1; i <=n; ++i) {
			for (int j = 1; j <=m; ++j) {
				if (p[i-1] == '*') {
					bool one = dp[j-1][i] && (s[j-1]==p[i-2] || p[i-2]=='.');
					bool two = (i-2 >= 0) && dp[j][i-2]; // case s="mi", p = "mis*"
					dp[j][i] = one || two;
				} else {
					dp[j][i] = (p[i-1]==s[j-1] || p[i-1]=='.') && dp[j-1][i-1]; 
				}
			}
		}

		return dp[m][n];
	}
};
