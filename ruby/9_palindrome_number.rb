# @param {Integer} x
# @param {Boolean}

def is_palindrome(x)
  return false if x < 0
  return true if x == 0

  str = x.to_s
  left, right = 0, str.length - 1
  while left < right 
     return false if str[left] != str[right]
     left += 1
     right -= 1
  end
  
  return true
end


def is_palindrome(x)
  return false if x < 0
  return true if x == 0

  sum = 0
  original = x
  while x > 0
    x, remainder = x.divmod(10)
    sum = sum * 10 + remainder
  end  
  
  sum == original

end


