# @param {String} s
# @return {Integer}


def length_of_longest_substring(s)
  current_begin = 0
  max_len = 0
  hash = Hash.new

  for i in 0...s.length
    if hash[s[i]] == nil || hash[s[i]] < current_begin #substring should continuous
      max_len = [max_len, i - current_begin + 1].max
    else
      current_begin = hash[s[i]] + 1
      max_len = [max_len, i - current_begin + 1].max
    end

    hash[s[i]] = i
  end

  max_len

end

puts length_of_longest_substring('abba') # 'abcabcbb' 'dvdf' 'pwwkew'
