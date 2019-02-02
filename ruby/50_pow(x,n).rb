# @param {Float} x
# @param {Integer} n
# @return {Float}

# 让我们实现x的n次方
# 二分，每次对n取余，如果余数为0，则将x平方，n除2，也就是等于 x^n => x^2^n/2
# 如果余数不为0，则res乘当前x，x继续平方，n除2
# 最后返回res即可

def my_pow(x, n)
    return 1 if n == 0
    return 1 / my_pow(x, -n) if n < 0

    res = 1.0
    while n != 0
        res *= x if n%2 != 0
        x *= x

        puts "n=#{n}, res=#{res}, x=#{x}"
        n /= 2
    end

    res
end

puts my_pow(2, 10)