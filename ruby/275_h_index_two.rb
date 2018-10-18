# @param {Integer[]} citations
# @return {Integer}

# 题目要求和274 一样， 给定数组时升序的，要求我们时间复杂度O(logN)， 所以得二分查找
# 如果我们不使用二分查找，整个遍历的话，也就是在 [ [len-idx, citations[idx]].min ] 数组中找最大的值
# 使用二分的话肯定是从中间找起，当 len-mid == citations[mid]
# 此时如果往左 [len-(mid-1), citations[mid-1]].min, len-(mid-1) > len-mid(citations[mid]), 而citations[mid-1] < citations[mid], 所以取min就是citations[mid-1]
# 此时如果往右 [len-(mid+1), citations[mid+1]].min, len-(mid+1) < len-mid(citations[mid]), 而citations[mid+1] > citations[mid], 所以取min就是len-(mid+1)
# 而citations[mid-1] 和 len-(mid+1) 都小于 len-mid, 所以当len-mid == citations[mid]， 直接返回，此时就是最大值

# 如果 len-mid > citations[mid], 则说明需要增加idx（也就是往右，这样差就会变小），所以left = mid+1
# 如果 len-mid < citations[mid], 则说明需要减小idx（也就是往左，这样差就会变大），所以right = mid-1

# 重复

# 直到left>right, 返回len-left 即可，此时left即为最小的，所以len-left也就是最大的（会过滤一些边界情况）

def h_index(citations)
	left, right = 0, citations.size-1
	
	while left <= right
		mid = left + (right-left)/2
		case citations.size-mid <=> citations[mid]
		when 0
			return citations.size-mid
		when 1
			left = mid+1
		when -1
			right = mid-1
		end
	end

	citations.size-left
end

nums = [0,1,5,7,9]
h_index(nums)
