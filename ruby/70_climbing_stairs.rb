# @param {Integer} n
# @return {Integer}

# 题目给定n表示n个台阶的楼梯，同时给定一次可以跨1个或2个台阶，求所有不同的爬完的可能
# 动态规划，主要是找到dp[n] = dp[n-1] + dp[n-2]，同时dp[0] = 0, dp[1] = 1, dp[2] = 2

def climb_stairs(n)
    return n if n < 4
    dp = Array.new(n+1, 0)

    for i in 0..n
    	if i < 4
    		dp[i] = i 
    	else
    		dp[i] = dp[i-1] + dp[i-2]
    	end
    end

    dp[n]
end