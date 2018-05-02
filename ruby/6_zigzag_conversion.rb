# @param {String} s
# @param {Integer} num_rows
# @return {String}



def convert(s, num_rows)
  return '' if s.length == 0 || s == nil
  return s if num_rows <= 1

  arr = Array.new(num_rows, '')
  row = 0
  is_add = true

  for i in 0...s.length
    if row > num_rows - 1
      row = num_rows - 2
      is_add = false
    end

    if row < 0
      row = 1
      is_add = true
    end

    arr[row] += s[i]

    is_add ? row += 1 : row -= 1
  end

  result = ''

  arr.each do |str|
    result += str
  end

  return result
end


# arr = Array.new(8) { Array.new(8, 0) }
# puts arr
