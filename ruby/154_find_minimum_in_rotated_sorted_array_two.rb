# @param {Integer[]} nums
# @return {Integer}


# 找到被旋转的数组中最小的，其实也就是找到数组的head, 和153相比，此时数组会出现重复元素
# 虽然有重复元素，但是使用之前的第一种方法，找到数组的首元素，也就是最小的元素，也就是可以的

# 同样的也可以使用 类似 153 的思路，只是此时需要过滤掉重复元素
def find_min(nums)
	return -1 if nums.empty?
	return nums[0] if nums.size == 1 || nums[0] < nums[nums.size-1]

	left, right = 0, nums.size-1
	while left <= right
		while left < right && nums[left+1] == nums[left]
			left += 1
		end
		return nums[left] if left == right
		return nums[left+1] if nums[left+1] < nums[left]

		if right > left && nums[right-1] == nums[right]
			right -= 1
		end
		return nums[right] if left == right
		return nums[right] if nums[right-1] > nums[right]

		left += 1
		right -= 1
	end

	-1
end


# 不过既然使用了二分，也是可以用mid的方法来写
def find_min_version2(nums)
	return -1 if nums.empty?
	return nums[0] if nums.size == 1 || nums[0] < nums[nums.size-1]

	res = nums[0]
	left, right = 0, nums.size-1
	while left < right-1
		mid = left + (right-left)/2
		if nums[left] < nums[mid]
			res = [res, nums[left]].min 
			left = mid+1
		elsif nums[left] > nums[mid]
			res = [res, nums[right]].min 
			right = mid
		else
			left += 1
		end
	end

	res = [res, nums[left]].min 
	res = [res, nums[right]].min
	res
end


nums = [1, 1]
puts find_min(nums)