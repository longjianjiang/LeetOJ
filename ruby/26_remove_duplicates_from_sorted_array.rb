# @param {Integer[]} nums
# @return {Integer}


# 给定有序数组，删除数组中重复的元素
# 很直接的思路，给定一个cursor遍历，依次删除重复的元素，最后返回数组的长度即可
# 移动cursor的注意，因为每次删除重复元素，数组长度在减小，所以移动cursor只可在遇到不重复元素后才可往前移动

def remove_duplicates(nums)
	return nums.size if nums.size < 2

	cursor, num = 1, nums[0]

	while cursor < nums.size
		if nums[cursor] == num
			nums.delete_at(cursor)
		else 
			num = nums[cursor]
			cursor += 1
		end
	end

	nums.size
end

# 本题中有说明为什么此方法返回的是新数组的长度，因为我们使用此方法返回的数组，大多为遍历操作，所以返回数组长度即可进行在有效范围内遍历。
# 所以我们可以不需要进行删除操作，只需要将原数组的前n个，也就是不重复的n个元素放在最前，
# 其他的可以不用考虑，因为使用者根据返回的count并不会去取n后面的元素。
# 所以本方法同样的设置一个cursor，遍历数组，遇到重复元素cursor往前移动，否则依次更新数组中前n个元素的值

def remove_duplicates_version2(nums)
	cursor, count = 0, 0
	while cursor < nums.size
		num = nums[cursor]
		cursor += 1
		while nums[cursor] == num
			cursor += 1
		end

		nums[count] = num
		count += 1
	end

	count
end

nums = [0,0,1,1,1,2,2,3,3,4]

puts remove_duplicates_version2(nums)
puts nums.inspect


