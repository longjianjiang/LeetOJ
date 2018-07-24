# @param {String[]} strs
# @return {String}


# 给定一个字符串数组，找出最长的公共前缀
# 以第一个字符串为参照，依次遍历，同时查看剩余字符串中每一位是否相等，进行记录次数，最后按次数截取子串即可
# ruby中范围 1..-1 , 等于1到最后一个


def longest_common_prefix(strs)
    return '' if strs.empty?

    str, len = strs[0], 0
    str.chars.each_with_index do |ch, idx|
    	break if strs[1..-1].any? { |c| c[idx] != ch }
    	len += 1
    end

    str[0, len]
end

strs = ['ab', 'nan', 'jiang', 'jjj']

puts strs[1..-1]
puts strs[1..strs.length-1]
