# @param {Integer[]} nums
# @return {Integer[][]}


# 给定一组数，找出不重复的三元组，使得三元组和为0
# 首先将数组排序，遍历数组，首先求出当前数字的相反数target，接着在该数字后的数组中寻找和为targe的二元组，将其组合成一个三元组

def three_sum(nums)
	nums = nums.sort

    res = []

	for i in 0...nums.length-2
		next if i > 0 && nums[i] == nums[i-1]

		target = -nums[i]
		two_tuples = get_two_sum(nums, i+1, target)
		for elem in two_tuples
			res << [nums[i], elem[0], elem[1]]
		end
	end

	res
end

def get_two_sum(nums, idx, target)
	two_tuples = []

	i, j = idx, nums.length-1
	while i < j
		if i > idx && nums[i] == nums[i-1]
			i += 1
			next
		end

		if j < nums.length-1 && nums[j] == nums[j+1]
			j -= 1
			next
		end

		if nums[i] + nums[j] == target
			two_tuples << [nums[i], nums[j]]
			i += 1
			j -= 1
		elsif nums[i] + nums[j] < target
			i += 1
		else
			j -= 1
		end
	end

	two_tuples
end


# 看到一种和之前类似的方法，不过此方法效率更好一些

def three_sum_v2(nums)
	nums = nums.sort

	# 求出数组中数字>=0 的索引
    bound = (0...nums.size).bsearch { |i| nums[i] >= 0 }

    return [] if bound.nil?

    result = []

    # 遍历0..bound， 然后和第一种方法类似，求two_sum
    0.upto(bound) do |ai|
    	next if ai > 0 && nums[ai] == nums[ai-1]

    	bi, ci = ai + 1, nums.length-1
    	subsum = -nums[ai]

    	# unless subsum >= (nums[bi] || 0) * 2

    	while bi < ci
    		case nums[bi] + nums[ci] <=> subsum
    		when -1
    			bi += 1
    		when 1
    			ci -= 1
    		when 0
    			result << [nums[ai], nums[bi], nums[ci]]
    			bi += 1
    			bi += 1 while bi < ci && nums[bi] == nums[bi-1]
    			ci -= 1
    			ci -= 1 while bi < ci && nums[ci] == nums[ci+1]
    		end
    	end
    end

    result
end

nums = [-1, 0, 1, 2, -1, -4]
