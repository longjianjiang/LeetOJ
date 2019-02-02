# @param {Integer} x
# @return {Integer}

# 开平方，只保留整数
# 当x大于1，平方根的范围为[1, x], 我们需要寻找的就是最后一个num的平方是小于等于x。
# 所以我们假定right指向的num平方时第一个大于x，所以我们返回right-1，即是最后一个num的平方是小于等于x。

def my_sqrt(x)
	return x if x <= 1
	left, right = 1, x
	while left < right
        mid = left + (right - left) / 2
        if x/mid < mid # 此时mid大了，也就是 mid * mid > x, 需要尝试往左寻找平方比x小的num
            right = mid
        else 
            left = mid+1
        end
	end

	right-1
end