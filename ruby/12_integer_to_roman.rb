# @param {Integer} num
# @return {String}


# 将1-3999的数字转成罗马数字，思路做除法记录各个位的数，分别用罗马数字代替
# 比如1024，1用一千的罗马数字代替，0则为空字符，2用20的罗马数字，最后4用IV代替
# ruby 中的divmod方法，以一个数组返回（依次为商和余数）

def int_to_roman(num)
  w0 = ['', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX']
  w1 = ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC']
  w2 = ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM']
  w3 = ['', 'M', 'MM', 'MMM']

  str = ''
  num, rem = num.divmod(1000); str << w3[num]
  num, rem = rem.divmod(100); str << w2[num]
  num, rem = rem.divmod(10); str << w1[num]; str << w0[rem]

  str 
end

