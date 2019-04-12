# @param {Integer[]} nums
# @return {Integer}

# Input: [2,3,1,1,4]
# Output: 2

# 和55题类似，只是本题假设一定可以移动到末尾，求最短的移动步数
# 根据数组首元素来计算一个移动的索引范围[idx,len]，从该范围中进行遍历，查看对应索引所能到达的最大步数，
# 这里的步数也就是数组元素的索引当没有越界的时候
# 如果当前范围能够到达的最大位置没有到末尾，更新这个范围，直到到达末尾

def jump(nums)
    return 0 if nums.size == 1

    max, submax = 0, 0
    lbound, rbound, maxbound = 0, nums.size-1, 0
    step = 1

    while true
        lbound.upto(maxbound) do |idx|
            submax = idx + nums[idx]
            max = submax if submax > max
            return step if max >= rbound
        end

        step += 1
        lbound, maxbound = maxbound+1, max
    end
end
