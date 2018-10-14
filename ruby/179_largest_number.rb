# @param {Integer[]} nums
# @return {String}

# Input: [10,2]
# Output: "210"

# Input: [3,30,34,5,9]
# Output: "9534330"


# 给定非负数组，要求我们拼接元素构成一个最大的数字，以字符串的形式返回
# 其实只需要我们将数组排好序，然后拼接成字符串返回即可，也就是需要我们来自定义规则排序
# 其实本题的排序规则就是两个数字符串相加的结果谁大返回谁，例如 "34", "9" : "349" <=> "943"
# 最后需要注意处理多个零的情况，因为当结果为0时，返回 "0"即可

def largest_number(nums)
	f = ->(x1, x2) { x2 + x1 <=> x1 + x2 }
	n = nums.map(&:to_s).sort(&f).reduce(&:+)
	return n[0] == "0" ? "0" : n
end

nums = [3,30,34,5,9]

puts largest_number(nums)
