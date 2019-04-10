# @param {Character[][]} matrix
# @return {Integer}

# 给定一个矩形，找出1为边的最大正方形，返回其面积
# 使用动态规划，转化为求边长的问题。单个数字1的正方形面积为1，从(1,1)开始，如果该点周围的三个点都是1，该点对应的边长就为2。
# 得到递推公式 dp[i][j] = [dp[i-1][j], dp[i][j-1], dp[i-1][j-1]].min + 1

def maximal_square(matrix)
    return 0 if matrix.empty? || matrix[0].empty?
    m, n = matrix.size, matrix[0].size

    res = 0
    # dp = Array.new(m, Array.new(n, 0))
    dp = Array.new(m) { Array.new(n, 0) }

    for i in 0...m 
        for j in 0...n
            if i == 0 || j == 0
                dp[i][j] = matrix[i][j].to_i
            elsif matrix[i][j] == '1'
                dp[i][j] = [dp[i-1][j], dp[i][j-1], dp[i-1][j-1]].min + 1
            end

            res = dp[i][j] if dp[i][j] > res
        end
    end

    res * res
end

# 1 1 1 1 1
# 1 1 1 1 1
# 1 1 1 1 1
# 1 1 1 1 1

# 1 0 1 0 0
# 1 0 1 1 1
# 1 1 1 1 1
# 1 0 0 1 0

# (4,3) => (4,2) (3,3)
# dp[i][j] = min(dp[i][j-1] + dp[i-1][j])

matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
maximal_square(matrix)


m, n = matrix.size, matrix[0].size

dp1 = Array.new(m) { Array.new(n, 0) }
dp2 = Array.new(m, Array.new(n, 0))


puts dp1.inspect
puts dp2.inspect

dp1[0][0] = 1
dp2[0][0] = 1

puts dp1.inspect
puts dp2.inspect