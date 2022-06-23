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
给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。

子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
*/

// dp, dp[idx][len] 表示子串中回文的长度。
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int nsize = s.size();
		if (nsize <= 1) { return nsize; }
		int res = 1;
		vector<vector<int>> dp(nsize+1, vector<int>(nsize+1, 0));
		// dp[idx][len]
		for (int i = 0; i < nsize; ++i) {
			dp[i][0] = 0;
			dp[i][1] = 1;
		}
		// "aab"
		// "abb"
		// "ac"
		// "cbbab"
		for (int len = 2; len <= nsize; ++len) {
			for (int idx = 0; idx < nsize; ++idx) {
				if (idx + len <= nsize) {
                    if (s[idx+len-1] == s[idx]) {
                        dp[idx][len] = 2 + dp[idx+1][len-2];
                    } else {
						dp[idx][len] = max(dp[idx+1][len-1], dp[idx][len-1]);
                    }
                    res = max(res, dp[idx][len]);
				}
			}
		}
		return res;
    }
};

void unit_test() {
	Solution s;

	cout << s.longestPalindromeSubseq("bbbab") << endl;
	cout << s.longestPalindromeSubseq("cbbd") << endl;
	cout << s.longestPalindromeSubseq("abc") << endl;
	cout << s.longestPalindromeSubseq("aab") << endl;
	cout << s.longestPalindromeSubseq("abb") << endl;
}

int main() {
	unit_test();
	return 0;
}
