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

// 返回所有子串中回文串的个数；
// 1> brute force；
class Solution {
public:
	int countSubstrings(string s) {
		int nsize = s.size();
		if (nsize <= 1) { return nsize; }

		int res = nsize;
		vector<vector<int>> dp(nsize+1, vector<int>(nsize+1, 0));
		// dp[idx][len]
		for (int i = 0; i < nsize; ++i) {
			dp[i][0] = 1;
			dp[i][1] = 1;
		}
		// "abc"
		// len = 2, idx = 0; dp[1][0] s[1] s[0]
		// len = 2, idx = 1; dp[2][0] s[1] s[1]
		for (int len = 2; len <= nsize; ++len) {
			for (int idx = 0; idx < nsize; ++idx) {
				if (idx + len <= nsize) {
					dp[idx][len] = dp[idx+1][len-2] && s[idx+len-1] == s[idx];
					if (dp[idx][len]) {
						res++;
					}
				}
			}
		}
		return res;
	}
    int countSubstrings2(string s) {
		// "aaa"
		// "aba"
		// "aaaaa"
		// "aaaba"
		// "sooos"

		// "aa"
		// "aaba"
		// "baab"
		// "abab"

		int nsize = s.size();
		if (nsize <= 1) { return nsize; }

		auto isPalindrmic = [](string s) {
			int l = 0, r = s.size()-1;
			while (l < r) {
				if (s[l++] != s[r--]) {
					return false;
				}
			}
			return true;
		};
		int res = 0;
		// 0,1; 0,2; 0,3;
		// 1,1; 1,2;
		// 2,1
		for (int i = 0; i < nsize; ++i) {
			for (int j = 1; j <= nsize - i; ++j) {
				string tmp = s.substr(i, j);
				if (isPalindrmic(tmp)) { ++res; }
			}
		}

		return res;
    }
};

void unit_test() {
	Solution s;


	cout << s.countSubstrings("aaa") << endl;
	cout << s.countSubstrings("abc") << endl;
}

int main() {
	unit_test();
	return 0;
}
