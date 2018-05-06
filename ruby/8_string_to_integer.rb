# @param {String} str
# @param {Integer}


# Limits on Integer Constants
INT_BIT = 32
INT_MAX =  2 ** (INT_BIT - 1) - 1
INT_MIN = -2 ** (INT_BIT - 1)


def my_atoi(str)
  idx = 0
  idx += 1 while str[idx] == ' '

  case str[idx]
    when '-'; idx, is_positive = idx + 1, false
    when '+'; idx, is_positive = idx + 1, true
    else    ; positive = true
  end

  result = 0
  str[idx..-1].each_char do |char|
    case char
      when '0'; result = result * 10 + 0
      when '1'; result = result * 10 + 1
      when '2'; result = result * 10 + 2
      when '3'; result = result * 10 + 3
      when '4'; result = result * 10 + 4
      when '5'; result = result * 10 + 5
      when '6'; result = result * 10 + 6
      when '7'; result = result * 10 + 7
      when '8'; result = result * 10 + 8
      when '9'; result = result * 10 + 9
      else    ; break
    end
  end

  is_positive ? [result, INT_MAX].min : [-result, INT_MIN].max

end


puts my_atoi('  +0 123')
