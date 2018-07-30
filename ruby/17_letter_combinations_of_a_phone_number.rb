# @param {String} digits
# @return {String[]}


# 根据电话拨号界面上每个数字下面的字母，给定字符串（2-9), 求每个数字对应的字母所有可能组合
# 使用map 方法， letters.map(&:chars) == letters.map { |str| str.chars }
# 所以首先根据m， 将digits 利用 .chars 变成数组后， 根据m对应表将2-9，转成对应的字符串（'abc')
# 接着 map letters 将 'abc' 转成对应的 .chars ['a', 'b', 'c']
# 然后 reduce， 使用product方法， 该方法组合两个数组内所有元素的情况
# 最后 使用数组的 join方法， 将['a', 'c'] = > 'ac'


def letter_combinations(digits)
    m = {
    '1' => '',     '2' => 'abc', '3' => 'def',
    '4' => 'ghi',  '5' => 'jkl', '6' => 'mno',
    '7' => 'pqrs', '8' => 'tuv', '9' => 'wxyz',
                   '0' => ''
    }

    return [] if digits.length == 0
    return m[digits[0]].chars if digits.length == 1

    letters = digits.chars.map { |digit| m[digit] }
    letters.map(&:chars).reduce(&:product).map(&:join)
end


nums = [1, 2, 3, 4]
letters = ['abc', 'def']

puts letters.map(&:chars).inspect
puts letters.map { |str| str.chars }.inspect
puts letters.map(&:chars).reduce(&:product).inspect
puts letters.map(&:chars).reduce(&:product).map(&:join).inspect


puts nums.join.class
