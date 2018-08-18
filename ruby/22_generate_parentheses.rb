# @param {Integer} n
# @return {String[]}


# 给定n求n对括号的所有组合情况
# 想到使用递归，递归和普通函数没什么区别，只是注意回溯，同时注意n 和 n-1的关系
# _generate_parenthesis_(left, right, str, res) 方法是创建有效字符串，并存入数组
# left，right 分别代表左右括号的个数，left，right肯定等于n，此时字符串中还没有左括号和右括号
# 当left > right , 此时表示左括号的个数小于右括号个数，这时右括号在前面，此时括号肯定是不合法的，所以可以直接返回
# 当left，right等于0， 此时可以将字符串插入数组
# 当left > 0, right > 0时，依次拼接左括号和右括号，同时对left，right进行减减
# 通过一系列递归，最后即可完整的得到数组


def generate_parenthesis(n)

	# 另一种递归的思路，当n=1时，肯定只能返回(), 所以当n>1时，就可以获得n-1的答案，然后依次遍历答案List
	# 取list中每一个字符串，然后从0-len,依次插入(), 最后返回去重后新的数组即可
	if n == 1
		return ["()"]
	else
		last = generate_parenthesis(n-1)
		res = []

		last.each do |item|
			for i in 0..item.length
				tmp = item.clone
				s = tmp.insert(i, "()")
				res << s
			end
		end

		return res.uniq
	end


  [].tap do |result|
  	_generate_parenthesis_(n, n, '', result)
  end 
end

def _generate_parenthesis_(left, right, str, res)
	
	puts "left = #{left}, right=#{right}, str=#{str}, res = #{res.inspect}"

	return if left > right 
	if left == 0 && right == 0
		res << str
	else 
		_generate_parenthesis_(left-1, right, str + '(', res) if left > 0
		
		_generate_parenthesis_(left, right-1, str + ')', res) if right > 0
	end
end


puts generate_parenthesis(2).inspect

# str = "123"
# s = str
# s = s.insert(1, "~")

# puts str
# puts s 

