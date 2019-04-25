# @param {Integer[]} nums
# @return {Integer}

# 和53题类似，只是本题要求返回的是subarray的乘积。
# 因为乘法的关系，所以需要记录一个局部最小，这样就能保证负负得正的情况
# 同时因为每次只用到上一步的结果，覆盖，可以直接就一个变量来代替数组即可。

def max_product(nums)
    return 0 if nums.empty?
    return nums[0] if nums.size == 1

    max_local, min_local = nums[0], nums[0]
    global = nums[0]
    for i in 1...nums.size
    	tmp = max_local
    	max_local = [[nums[i], max_local*nums[i]].max, min_local*nums[i]].max
    	min_local = [[nums[i], tmp*nums[i]].min, min_local*nums[i]].min
    	global = [global, max_local].max
    end

    global
end