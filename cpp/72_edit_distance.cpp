// 给定两个单词，要求将word1变为word2，允许删除操作，替换操作，添加操作，求最短操作次数；
// 开始没有思路，后来看了一个解答，首先尝试递归的思路，虽然可以求出答案，但是会超时，
// 但是这个时候有了思路，为下面的动态规划的解做了一个铺垫。
// 这题需要用动态规划，dp是一个二维数组，dp[i][j]表示的是，word1的[0,i]子串变换到word2的[0,j]子串需要的次数，最后返回dp[m][n]就是word1变换到word2需要的次数。
// 以word1为 horse， word2为 ros 举例
/*
 * 	 x r o s 
 * x 0 1 2 3
 * h 1 1 2
 * o 2
 * r 3
 * s 4
 * e 5
 */
// 首先dp[0][x], dp[x][0]，表示从空变为对应长度的字符串。
// dp[1][1] => 因为word1和word2的首字符不想等，所以这个时候需要在上一次变换的三种变换方式中选择次数最小的加1，即是结果，
// dp[i-1][j] 对应的是删除操作，dp[i-1][j-1]对应的是替换操作，dp[i][j-1]对应的是添加操作。

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
