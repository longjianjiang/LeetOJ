class Solution {
public:
    int minDistance(string word1, string word2) {
		if (word1 == word2) { return 0; }
		int m = word1.size(), n = word2.size();

		if (word2.size() == 0) { return m; }
		if (word1.size() == 0) { return n; }

		if (word1[0] == word2[0]) { 
			return minDistance(word1.substr(1), word2.substr[1]);
		} else {
			return min(1+minDistance(word1, word2.substr(1)),
					   min(1+minDistance(word1.substr(1), word2), 1+minDistance(word1.substr(1), word2.substr(1)))
				   );
		}
    }

	int minDistanceDP(string word1, string word2) {
		if (word1 == word2) { return 0; }
		int m = word1.size(), n = word2.size();

		if (word2.size() == 0) { return m; }
		if (word1.size() == 0) { return n; }

		vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
		for (int i = 1; i <= m; ++i) { dp[i][0] = i; }
		for (int i = 1; i <= n; ++i) { dp[0][i] = i; }

		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (word1[i-1] == word2[j-1]) {
					dp[i][j] = dp[i-1][j-1];
				} else {
					dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
				}
			}
		}
		return dp[m][n];
	}
};
