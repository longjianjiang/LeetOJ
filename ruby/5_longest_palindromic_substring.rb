# @param {String} s
# @return {String}


def addPrefix(s)
  result = '^'
  for i in 0...s.length
    result += "\##{s[i]}"
  end
  result += "\#\$"
end


def longest_palindrome(s)
  return '' if s.length == 0 || s == nil

  t = addPrefix(s)
  p = Array.new(t.length, 0)
  c = 0
  r = 0
  res_len = 0
  res_idx = 0

  for i in 1...t.length
    i_mirror = c - (i - c)
    p[i] = r > i ? [r-i, p[i_mirror]].min : 0

    while t[i + 1 + p[i]] == t[i - 1 - p[i]]
      p[i] += 1
    end

    if i + p[i] > r
      c = i
      r = i + p[i]
    end

    if p[i] > res_len
      res_len = p[i]
      res_idx = i
    end
  end

  puts p.to_s

  return s[((res_idx-1-res_len) / 2), res_len]
end

def search(s, left, right, idx, len, vars)
  step = 1
  while left - step >= 0 && right + step < s.length
    break if s[left - step] != s[right + step]
    step += 1
  end

  wide = right - left + (2 * step - 1)
  if wide > len
    eval "len = #{wide}", vars
    eval "idx = left - #{step} + 1", vars
  end
end


def longest_palindrome_2(s)
  return '' if s.length == 0 || s == nil

  left = 0
  right = 0
  idx = 0
  len = 0

  for i in 0...s.length
    if s[i] == s[i+1]
      left = i
      right = i + 1
      search(s, left, right, idx, len, binding)
    end

    left = right = i
    search(s, left, right, idx, len, binding)
  end

  return s[idx, len]
end


# 判断字符串是否为回文数
def is_palindrome_from_two_side(s)
  return false if s == nil || s.length == 0

  firstIdx = 0
  endIdx = s.length - 1

  while firstIdx < endIdx
    if s[firstIdx] != s[endIdx]
      return false
    else
      firstIdx += 1;
      endIdx -= 1
    end
  end

  return true
end


def is_palindrome_from_center(s)
  return false if s == nil || s.length == 0

  center_one = (s.length + 1) / 2
  center_two = (s.length + 2) / 2

  while center_one > 0
    if s[center_one-1] != s[center_two-1]
      return false
    else
      center_one -= 1
      center_two += 1
    end
  end

  return true
end


longest_palindrome('abab')
