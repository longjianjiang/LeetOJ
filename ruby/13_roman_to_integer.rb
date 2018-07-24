# @param {String} s
# @return {Integer}


# 将1-3999的罗马数字转换成十进制的数字
# 从右往左依次遍历，根据每个字母所代表的数值，依次叠加，注意4，9这类情况，需要做减法
# ruby chars 方法返回字符数组，each_con(n), 返回n位的枚举，直到结束

def roman_to_int(s)
	map = {
		'I' => 1,
		'V' => 5,
		'X' => 10,
		'L' => 50,
		'C' => 100,
		'D' => 500,
		'M' => 1000
	}
    
    num = map[s[0]]

    s.chars.each_cons(2) do |c1, c2|
    	num += map[c2]
    	num -= map[c1] if map[c1] < map[c2]
    end 

    num
end


s = 'abcd'
s.chars.each_cons(3) do |c1, c2, c3|
	puts "c1 = #{c1}"
	puts "c2 = #{c2}"
	puts "c3 = #{c3}"
end