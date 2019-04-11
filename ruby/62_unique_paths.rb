# @param {Integer} m
# @param {Integer} n
# @return {Integer}

# 给定一个n行m列的矩形，从左上角移动到右下角，每次只能往下或者往右移动，问一共右多少种移动方案。
# 一种直观的思路使用深搜
# 另一个思路则使用动态规划，从右下角来看，移动到右下角的所有情况等于该点周围的两个点的情况之和，即dp[i][j] = dp[i-1][j] + dp[i][j-1]

def unique_paths(m, n) 
	return 0 if m == 0 || n == 0
	return 1 if m == 1 || n == 1

	dp = Array.new(n) { Array.new(m, 1) }
	for i in 1...n
		for j in 1...m
			dp[i][j] = dp[i-1][j] + dp[i][j-1]
		end
	end

	dp[n-1][m-1]
end
