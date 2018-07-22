# @param {String} s
# @param {String} p
# @return {Boolean}

# 判断字符串是否匹配
# p 为模式串，含有 `*` , `.`两种特殊字符
# . 可以表示任何一个 a-z 的字符
# * 可以表示0个或多个*前面的字符


# 该方法使用递归
# 1.首先判断p长度如果 `>=` 2， 则看第二个是否为*（第一个字符为*其实可以当作普通字符来看待）。
# 2.如果第二个字符不是*，则依次判断第一个字符是否匹配，然后递归的进行判断第二个字符；
# 3.如果第二个字符是*，则分两种情况：
# 3.1 可能存在*代表0个前面的字符，所以直接判断s和p从idx为2开始的子串；
# 3.2 也有可能存在*代表1个或多个前面的字符，所以先判断第一个字符是否匹配，然后递归的判断s从idx为1的子串和p；


def is_match(s, p)

	return is_match(s, 0, p, 0)

	if p.empty?
		return s.empty?
	end

	first_match = s.length > 0 && (s[0] == p[0] || p[0] == '.')

	if p.length >= 2 && p[1] == '*'
		return is_match(s, p[2..p.length-1]) || ( first_match && is_match(s[1..s.length-1], p) )
	else
		return first_match && is_match( s[1..s.length-1], p[1..p.length-1] )
	end
end


def is_match(s, sBegin, p, pBegin)

	if pBegin >= p.length
		return sBegin >= s.length
	end

	first_match = sBegin < s.length && ( s[sBegin] == p[pBegin] || p[pBegin] == '.' )

	if pBegin <= p.length - 2 && p[pBegin + 1] == '*'
		return is_match(s, sBegin, p, pBegin + 2) || (first_match && is_match(s, sBegin+1, p, pBegin))
	else
		return first_match && is_match(s, sBegin+1, p ,pBegin+1)
	end

end







