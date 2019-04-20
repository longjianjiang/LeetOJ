# @param {Integer[]} prices
# @return {Integer}

# 给定数组为股票交易价格，只允许交易一次，开始新的交易之前必须卖了之前的股票，求最大收益
# 一次遍历，找到一个最低价，然后求一次差值即可，就是最大收益

def max_profit(prices)
	profit = 0
	min_price = prices[0]

	for i in 1...prices.size
		min_price = prices[i] if prices[i] < min_price
		profit = prices[i] - min_price if prices[i] - min_price > profit
	end

	profit
end

arr = [7,6,4,3,1] #[7,1,5,3,6,4]

puts max_profit(arr)