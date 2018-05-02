# @param {Integer} x
# @return {Integer}



def reverse(x)
  is_positive = x >= 0

  result = x.to_s.reverse.to_i

  return 0 if result > 2**31 - 1 || result < 0 - 2**31

  return is_positive ? result : 0 - result
end

# Ruby作整除运算时对结果进行向下（负无穷大）取整，而C则是向零取整。
# 所以，Ruby中-7%3的结果就是2，而非-1，-7/3的结果就是-3，而非-2
# 这样的结果是为了满足(a/b)*b+(a%b)=a这一等式。
# 所以👇方法在ruby中会死循环，C中正常
def reverse_integer(x)
  result = 0

  while x != 0
    result = 10 * result + (x % 10)
    x /= 10
  end

  return 0 if result > 2**31 - 1 || result < 0 - 2**31

  return result
end
