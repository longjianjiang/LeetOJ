# @param {Integer[]} nums
# @return {Integer}

# 给定数组，求一个连续subarray，要求subarray和最大，返回和
# 动态规划，dp[i] = max(nums[i], dp[i-1]+nums[i])，这样每一次使用到上一步的最大值，最后返回dp.max即可

def max_sub_array(nums)
    dp = Array.new
    dp[0] = nums[0]
    for i in 1...nums.size
        dp[i] = [nums[i], dp[i-1]+nums[i]].max
    end
    
    dp.max
end