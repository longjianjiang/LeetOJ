# @param {Integer[]} digits
# @return {Integer[]}

# 给定一个数组，数组中的数字代表一个非负的整数，将这个数字加1，然后依次存入数组返回
# 一个直觉的思路，倒序遍历数组，加1处理好进位，依次存入数组, 然后倒序返回即可

def plus_one(digits)
	digits = digits.reverse

	res = Array.new
	sum, carry = 0, 1
	for i in 0...digits.size
		num = digits[i]
		sum = carry + num
		carry = sum / 10
		res.push(sum % 10)
	end

	res.push(carry) if carry > 0

	res.reverse
end

digits = [9]
puts plus_one(digits).inspect

