# @param {Float} x
# @param {Integer} n
# @return {Float}

# 让我们实现x的n次方

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