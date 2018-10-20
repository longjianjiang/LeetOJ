# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer}

# Input: nums = [4,5,6,7,0,1,2], target = 0
# Output: 4

# Input: nums = [4,5,6,7,0,1,2], target = 3
# Output: -1

# 给定一个旋转过的升序数组，要求找到制定target的index，找不到返回-1，要求时间复杂度为O(logN)

def search(nums, target)
    left, right = 0, nums.size-1
    while left <= right
        mid = left + (right-left)/2
        return mid if nums[mid] == target

        if nums[mid] < nums[right]
            if target > nums[mid] && target <= nums[right]
            	left = mid + 1
            else
            	right = mid - 1
            end
        else
        	if target >= nums[left] && target < nums[mid]
        		right = mid -1
        	else
        	    left = mid + 1
        	end
        end
    end

    -1
end