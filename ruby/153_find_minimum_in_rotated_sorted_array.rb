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