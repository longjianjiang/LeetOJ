# @param {Integer[]} nums
# @param {Integer} val
# @return {Integer}


# 给定数组删除数组中所有为val的元素
# 遍历数组，删除元素等于val的元素即可


def remove_element(nums, val)
    cursor = 0
    while cursor < nums.size
    	if nums[cursor] == val
    		nums.delete_at(cursor)
    	else
    		cursor += 1
    	end
    end

    nums.size
end


nums = [0,1,2,2,3,0,4,2]
val = 2

puts remove_element(nums, val)
puts nums.inspect