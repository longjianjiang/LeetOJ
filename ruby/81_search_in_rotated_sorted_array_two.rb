# @param {Integer[]} nums
# @param {Integer} target
# @return {Boolean}

# Input: nums = [2,5,6,0,0,1,2], target = 0
# Output: true

# 给定一个旋转过的升序数组，要求寻找target，返回bool，此时数组可能有重复元素
# 思路同 33题

# 本题使用的是与right相比，其实道理和用left是一样的
def search(nums, target)
    left, right = 0, nums.size-1
    while left <= right
    	mid = left + (right-left)/2

    	return true if nums[mid] == target

    	if nums[mid] < nums[right]
    		if target > nums[mid] && target <= nums[right]
    			left = mid+1
    		else
    			right = mid-1
    		end
    	elsif nums[mid] > nums[right]
    		if target < nums[mid] && target >= nums[left]
    			right = mid-1
    		else
    			left = mid+1
    		end
    	else
    		right -= 1
    	end
    end

    false
end


# 另一种思路，因为数组被旋转过，所以找到数组的首元素，这样数组也拆分为两个有序的数组，此时在按照原始的二分查找即可

def find_nums_head(nums)
	for i in 1..nums.size-1
		return i if nums[i] < nums[i-1]
	end

	return 0
end

def search_version2(nums, target)
	head = find_nums_head(nums)

	if head == 0
		return nums.bsearch { |i| target <=> i } != nil
	else
		return nums.slice(0...head).bsearch { |i| target <=> i  } != nil ||
		       nums.slice(head...nums.size).bsearch { |i| target <=> i } != nil
	end
end


nums = [2,5,6,0,0,1,2]
puts search_version2(nums, 0)


