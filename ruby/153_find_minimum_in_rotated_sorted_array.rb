# @param {Integer[]} nums
# @return {Integer}
def find_nums_head(nums)
    for i in 1..nums.size-1
        return i if nums[i] < nums[i-1]
    end
    0
end

# 找到被旋转的数组中最小的，其实也就是找到数组的head
# 因为数组是升序的，只要nums[i] < nums[i-1]，那么i就是head，返回[head] 即可

def find_min(nums)
    head = find_nums_head(nums)
    nums[head]
end

# 我们可以利用上述思路，从left，right两个方向判断，加快速度

def find_min_version2(nums)
	return -1 if nums.empty?
	return nums[0] if nums.size == 1 || nums[0] < nums[nums.size-1]

	left, right = 0, nums.size-1
	while left <= right
		return nums[left+1] if nums[left+1] < nums[left]
		return nums[right] if nums[right-1] > nums[right]
		left += 1
		right -= 1
	end

	-1
end