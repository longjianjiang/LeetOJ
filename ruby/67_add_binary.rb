# @param {String} a
# @param {String} b
# @return {String}

# Input: a = "11", b = "1"
# Output: "100"
# Input: a = "1010", b = "1011"
# Output: "10101"

# 给定两个二进制数的字符串形式，将其相加，最后返回和的二进制形式
# 将两个字符串从低位开始相加处理好进位，依次添加到字符串中即可

def add_binary(a, b)
	a, b = b, a if a.size < b.size

	a, b = a.reverse, b.reverse
    res, sum, carry = "", 0, 0
    
    for i in 0...a.size
    	if i < b.size
    		sum = (carry + a[i].to_i + b[i].to_i) % 2
	    	carry = (carry + a[i].to_i + b[i].to_i) / 2
	    else
	    	sum = (carry + a[i].to_i) % 2
	    	carry = (carry + a[i].to_i) / 2
    	end
    	
    	res = sum.to_s + res
    end

    res = carry.to_s + res if carry > 0

    res
end


a, b = "0", "0"
puts add_binary(a,b)