# @param {String} s
# @return {Boolean}

# 本题和125类似，只是本题中允许删除一个字符，判断是否为回文，而且字符串中只包含小写字母
# 思路和之前类似，只是遇到不匹配时，需要进行跳过一次，这一次既可以左也可以右
# 例如往左跳一步，此时还是左右两边遍历，这一次遍历只找能不能成功，出现失败直接进行下一次
# 现在往右跳一步，此时左右两边遍历，而且规则就和正常的一样了

def valid_palindrome(s)
    return true if s.empty?

    left, right = 0, s.size-1
    while left < right 
        if s[left] != s[right]
            l, r = left + 1, right
            while l < r 
                break if s[l] != s[r]
                l += 1
                r -= 1
                return true if l > r
            end
            right -= 1
            while left < right
                if s[left] != s[right]
                    return false
                else
                    left += 1
                    right -= 1
                end
            end
        else
            left += 1
            right -= 1
        end
    end

    return true
end


puts valid_palindrome("abca")