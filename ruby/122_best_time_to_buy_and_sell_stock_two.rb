# @param {Integer[]} prices
# @return {Integer}

# 给定数组为股票交易价格，不限制交易次数，开始新的交易之前必须卖了之前的股票，求最大收益
# 因为不限次数，所以遍历一次，将收益相加即得到最大收益

def max_profit(prices)
    prices.each_cons(2).map { |e| [e[1]-e[0], 0].max }.reduce(0, &:+)

    # return 0 if prices.size < 2

    # profit = 0
    # for i in 0...prices.size-1
    #     diff = prices[i+1] - prices[i]
    #     profit += diff if diff > 0
    # end

    # profit
end

arr = [1,2,3,4,5]

