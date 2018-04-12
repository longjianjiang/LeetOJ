# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}


def two_sum(nums, target)
  dict = Hash.new

  nums.each_with_index do |item, idx|
    left = dict[target - item]
    return [idx, left] if left != nil
    dict[item] = idx
  end
end


nums = [2, 7, 11, 15]
target = 9
puts two_sum(nums, target)
