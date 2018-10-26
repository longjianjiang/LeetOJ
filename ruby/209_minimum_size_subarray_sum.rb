# @param {Integer} s
# @param {Integer[]} nums
# @return {Integer}

# Input: s = 7, nums = [2,3,1,2,4,3]
# Output: 2
# Explanation: the subarray [4,3] has the minimal length under the problem constraint.

# 一种依次遍历的方法，时间复杂度O(n^2), 超时了，所以得换种方法
# 不过通过这种方法的实验，知道了以下几种特殊情况
# 1. 数组为空
# 2. 数组和小于s
# 3. 数组中一个元素大于s

def min_sub_array_len(s, nums)
    return 0 if nums.empty? || nums.sum < s
    left, right = 0, -1
    res = Array.new
    sum = nums[left]
    while right < nums.size
        sum += nums[right] if right > left
        if sum >= s
            return 1 if right == -1
            res.push(right-left+1)
            left += 1
            sum = nums[left]
            right = -1
            next
        else
            right += 1
        end
    end
    res.min
end

# 另一种思路，我们一次遍历，每次累加sum，当sum >= s 时，此时说明当前的长度是符合要求的
# 然后将left往后移动，每次减小长度，最后返回最短的，此时时间复杂度为O(n)

def min_sub_array_len_version2(s, nums)
    return 0 if nums.empty? || nums.sum < s 
    
    sum, left = 0, 0
    res = Array.new
    for i in 0...nums.size
        sum += nums[i]
        while sum >= s 
            res.push(i+1-left)
            sum -= nums[left]
            left += 1
        end
    end

    res.min
end

nums = [1,1] #[2,3,1,2,4,3] #[1,4,4]
puts min_sub_array_len(3, nums)

