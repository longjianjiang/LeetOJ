# @param {String} s
# @return {Boolean}

# 给定一个字符串，要求只统计字符串中的字母和数字，判断是否为回文
# 既然是判断回文思路其实是一样的，左右两个指针，判断是否相等，不过这里需要做跳过和大小写转换

def is_palindrome(s)
    return true if s.empty?

    left, right = 0, s.size-1
    while left <= right
        if /[a-zA-Z0-9]/.match(s[left]) == nil
            left += 1
            next
        end
        if /[a-zA-Z0-9]/.match(s[right]) == nil
            right -= 1
            next
        end

        if s[left].downcase != s[right].downcase
            return false
        else
            left += 1
            right -= 1
        end

    end

    return true
end

s = "race a car"
puts is_palindrome(s)