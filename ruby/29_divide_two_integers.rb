# @param {Integer} dividend
# @param {Integer} divisor
# @return {Integer}

def divide(dividend, divisor)
end

def add(num1, num2)
    return num1 if num2 == 0
    sum = num1 ^ num2
    carry = (num1 & num2) << 1
    return add(sum, carry)
end 

def negative(num)
    add(~num, 1)
end

def subtraction(num1, num2)
    return add(num1, negative(num2))
end

# https://blog.csdn.net/ojshilu/article/details/11179911

puts add(5, 7)
puts subtraction(7, 5)

