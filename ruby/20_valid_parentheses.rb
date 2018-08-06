# @param {String} s
# @return {Boolean}


# 给定字符串由三种括号组成，判断是否合法，判断标准为括号两两闭合顺序正确同时必须同一种括号
# 可以使用栈，当括号为前一部分时，入栈；为后一部分时取top进行比较看是否为同一类型，否则返回false
# 最后看栈是否为空即可

def is_valid(s)
	stack = []

	s.each_char do |c|
		case c
		when '(', '[', '{'
			stack.push(c)
		when ')'
			return false if stack.pop != '('
		when ']'
			return false if stack.pop != '['
		when '}'
			return false if stack.pop != '{'
		end
	end

	stack.empty?
end
