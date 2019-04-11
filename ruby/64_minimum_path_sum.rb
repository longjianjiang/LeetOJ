# @param {Integer[][]} grid
# @return {Integer}

# 给定一个矩形，还是从左上角移动到右下角，返回所有路径中和最小的
# 思路还是和63 64 一样的，只是这里dp记录的是该位置和最小的结果，所以dp[i][j] = (dp[i-1][j], dp[i][j-1]).min + grid[i][j]

def min_path_sum(grid)
	m, n = grid[0].size, grid.size
    dp = Array.new(n) { Array.new(m, 0) }
	
	for i in 0...n
		for j in 0...m
			if i == 0 && j == 0
				dp[i][j] = grid[i][j]
			elsif i == 0
				dp[i][j] = dp[i][j-1] + grid[i][j]
			elsif j == 0
				dp[i][j] = dp[i-1][j] + grid[i][j]
			else
				dp[i][j] = [dp[i-1][j], dp[i][j-1]].min + grid[i][j]
			end
		end
	end

	dp[n-1][m-1]
end
