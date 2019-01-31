# @param {Integer} x
# @return {Integer}

# 开平方，只保留整数
# 当x大于1时，二分[1,x], 判断 x / mid 与 mid 大小关系，最后返回 right-1

def my_sqrt(x)
	return x if x <= 1
	left, right = 1, x 
	while left < right
		mid = left + (right - left) / 2
		if x / mid > mid
			left = mid + 1
		elsif x / mid == mid
			return mid
		else
			right = mid
		end
	end

	right-1
end