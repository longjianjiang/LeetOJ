# @param {Integer} num
# @return {Boolean}

# 给定一个数字让我们判断质数因子是不是只有 2 3 5 
# 直觉思路就是将 num 依次除以这三个数，如果最后为1则返回true
# 只是在除这三个数时，需要先事先判断 num 对这个三个数进行取余，当余数为0时才除

def is_ugly(num)
	while num >= 2
		if num % 2 == 0
			num /= 2
		elsif num % 3 == 0
			num /= 3
		elsif num % 5 == 0
			num /= 5
		else
			return false
		end
	end

	num == 1
end