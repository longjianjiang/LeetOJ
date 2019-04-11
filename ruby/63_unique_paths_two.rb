# @param {Integer[][]} obstacle_grid
# @return {Integer}

# 和63题类似，只是这里的矩形中添加来障碍，导致这个点不能通过，只需要判断即可，递推公式还是一样的

def unique_paths_with_obstacles(obstacle_grid)
	m, n = obstacle_grid[0].size, obstacle_grid.size
	dp = Array.new(n) { Array.new(m, 0) }
	for i in 0...n
		for j in 0...m
			if obstacle_grid[i][j] == 1
				dp[i][j] = 0
			else
				if i == 0 && j == 0
					dp[i][j] = 1
				elsif i == 0
					dp[i][j] = dp[i][j-1]
				elsif j == 0
					dp[i][j] = dp[i-1][j]
				else
					dp[i][j] = dp[i-1][j] + dp[i][j-1]
				end
			end
		end
	end	

	dp[n-1][m-1]
end
