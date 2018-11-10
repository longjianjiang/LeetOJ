# @param {Integer} n
# @return {String}

# 只能说本题Leetcode写的太不好了，看了几遍没看懂是什么规则，后来才知道是实现一个方法，给定n(n>=1)输出一个字符串。
# 规则如下：当n==1，直接返回"1"; 
#           n==2,count&say上一次也就是n==1时返回的数字(1),叫做1个1， =>记做"11"
#			n==3,count&say上一次也就是n==2时返回的数字(11),叫做2个1，=>记做"21"
# 			n==4,count&say上一次也就是n==3时返回的数字(21),叫做1个2，一个1, =>记做"1211"
# 			n==5,count&say上一次也就是n==4时返回的数字(1211),叫做1个1，1个2，2个1，=>记做"111221"
# 依次类推

# 其实我们可以发现我们需要做的其实就是从高位开始统计数字的连续重复的次数，最后合并起来即可

def count_and_say(n)
	return "" if n <= 0

	str = "1"
	n -= 1
	n.times do 
		char, count, tmp = str[0], 1, ""

		str[1..-1].each_char do |ch|
			if char == ch
				count += 1
			else
				tmp << count.to_s << char
				char, count = ch, 1
			end
		end
		tmp << count.to_s << char

		str = tmp
	end
	
	str
end


# puts count_and_say(1)
# puts count_and_say(2)
# puts count_and_say(3)
# puts count_and_say(4)
# puts count_and_say(5)
# puts count_and_say(6)
# puts count_and_say(7)