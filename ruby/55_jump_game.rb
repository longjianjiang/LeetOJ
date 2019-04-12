# @param {Integer[]} nums
# @return {Boolean}

# 给定非负数组，每个数字表示可以跳的最大步数，问是否能够到达数组末尾
# 数组中的每个位置索引加上其值等于能跳的最远步数，遍历数组，不断更新最大步数，当索引大于当前最大步数，此时证明不能到达末尾了

def can_jump(nums)
	return true if nums.size < 2
	step = nums[0]

	lbound, rbound = 1, nums.size-1
	while lbound <= rbound && lbound <= step
		step = lbound + nums[lbound] if lbound + nums[lbound] > step
		return true if step >= rbound

		lbound += 1
	end

	false
end