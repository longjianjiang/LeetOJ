# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer}

# Input: nums = [4,5,6,7,0,1,2], target = 0
# Output: 4

# Input: nums = [4,5,6,7,0,1,2], target = 3
# Output: -1


# 给定一个旋转过的升序数组，要求找到制定target的index，找不到返回-1，要求时间复杂度为O(logN)
# 查找问题，一般最优解就是二分查找了，所以这道题也不例外，需要二分查找，只是数组是被旋转过的
# 二分查找的步骤其实就是找到mid，然后根据条件进行选择左右区间即可，普通的有序数组，直接根据[mid]和target的大小比较即可知道选择哪个区间。
# 所以本题的难点就是在于如何寻找另一个选择区间的判断
# 首先找到mid，下面使用left和right 其实是一个道理，就是定位到一个更小的区间而已。

# 当我们定位到mid时，我们就以left为例好了，首先判断下[mid] 和 [left] 的大小
# <1> [mid] > [left], 接下来我们继续定位，如果此时 target<[mid] && target>=[left]，那么说明target肯定就在left..mid区间里了
# <2> [mid] < [left], 接下来我们继续定位，如果此时 target>[mid] && target<=[right], 那么说明target肯定就在mid..right区间里了
# <3> [mid] == [left], 数组中有重复元素或者mid==left时会出现，此时我们只需要将left往前移动一位即可，等于过滤掉重复元素的比较

def search(nums, target)
	left, right = 0, nums.size-1
	while left <= right
        mid = left + (right-left)/2
        return mid if nums[mid] == target

        if nums[mid] > nums[left]
        	if target >= nums[left] && target < nums[mid]
        		right = mid-1
        	else
        		left = mid+1
        	end
        elsif nums[mid] < nums[left]
        	if target > nums[mid] && target <= nums[right]
        		left = mid+1
        	else
        		right = mid-1
        	end
        else
        	left += 1
        end
	end

	-1
end

