# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[][]}


# Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
# [-2, -1, 0, 0, 1, 2]
# A solution set is:
# [
#   [-1,  0, 0, 1],
#   [-2, -1, 1, 2],
#   [-2,  0, 0, 2]
# ]

# 给定数组和一个target，求数组中所有四元组，要求四元组之和为target
# 两次循环，第一层循环从 ai => 0..nums.length-1
# 第二层循环从 di => nums.length-1..ai+3（ai+3，这样两边正好不重叠）
# 然后 bi = ai + 1, ci = di - 1, 又回到了之前的two_sum, 最后将ai，bi，ci，di加入数组存进res即可

def four_sum(nums, target)
    nums = nums.sort

    result = []
    0.upto(nums.length-1-3) do |ai|
    	next if ai > 0 && nums[ai] == nums[ai-1]

    	(nums.length-1).downto(ai+3) do |di|
    		next if di < nums.length-1 && nums[di] == nums[di+1]

    		subsum = target - (nums[ai] + nums[di])
    		bi, ci = ai + 1, di - 1
    		# next unless subsum.between?(nums[bi] * 2, nums[ci] * 2)

    		while bi < ci
    			case nums[bi] + nums[ci] <=> subsum
    			when 1
    				ci -= 1
    			when -1
    				bi += 1
    			when 0
    				item = [nums[ai], nums[bi], nums[ci], nums[di]]
    				result << item #if result.include?(item) == false
    				bi += 1
    				bi += 1 while bi < ci && nums[bi] == nums[bi-1]
    				ci -= 1
    				ci -= 1 while bi < ci && nums[ci] == nums[ci+1]
    			end
    		end
    	end
    end
    result
end

