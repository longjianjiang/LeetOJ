# @param {Integer[]} prices
# @return {Integer}

# 给定数组为股票交易价格，只允许交易两次，开始新的交易之前必须卖了之前的股票，求最大收益
# 全局最大收益 global[i][j]，表示i天交易j次的全局最大收益，递推公式如下，前一天的全局最大收益和当天的最大收益之间的最大值
# global[i][j] = max(global[i-1][j], local[i][j])
# 当天最大收益 local[i][j]，表示i天交易j次的最大收益，这种情况有点复杂，得分几种情况考虑，首先明确一点卖掉股票算完成一次交易
# 1> 当天买当天卖完成一次新的交易，此时local[i][j] = global[i-1][j-1]
# 2> 当天卖前一天买的完成一次新的交易，此时local[i][j] = global[i-1][j-1] + diff, diff = prices[idx]-prices[idx-1]
# 3> 当天卖之前买的股票，算完成一次新的交易，此时local[i][j] = local[i-1][j] + diff
# local[i-1][j] 表示的是前一天交易j次的收益，此时已经交易了j次，此时这个diff就是当天价格和前一天价格的差，所以local[i-1][j] + diff，
# 其实就想当于之前买然后以今天的价格卖出，完成一次交易，依然是j次。
# 所以综上，local[i][j] = max(global[i-1][j-1], local[i-1][j]) + diff
# 最后返回global[size-1][j]就是交易j次的最大收益

def max_profit(prices)
	return 0 if prices.size < 2

	local = Array.new(3, 0)
	global = Array.new(3, 0)

	idxs = [2, 1] # 因为需要global[i-1][j-1]，所以次数需要逆序，这样可以准备取到前一天的值
	for i in 0...prices.size-1
		diff = prices[i+1] - prices[i]
		idxs.each do |j|
			local[j] = [local[j], global[j-1]].max + diff
			global[j] = [global[j], local[j]].max
		end

		puts "---------#{i}----------"
		puts local.inspect
		puts global.inspect
	end

	global[2]
end

arr = [2,1,4,5,2,9,7]

puts max_profit(arr)