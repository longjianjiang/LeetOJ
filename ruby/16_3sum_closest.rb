# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer}

# 给定数组和target，求数组中三元组和最接近target的
# 思路和3Sum第二种方法类似，首先排序，求数组中前三个的和和target之前的distance
# 然后遍历数组，依次比较各个三元组和target之前的dis，最后取得dis最小的，返回target+dis即可


def three_sum_closest(nums, target)
    nums = nums.sort

    distance = nums[0..2].reduce(:+) - target

    0.upto(nums.length-3) do |ai|
    	bi, ci = ai + 1, nums.length-1

    	while bi < ci
    		sum = nums[ai] + nums[bi] + nums[ci]

    		dis = sum - target
    		return sum if dis == 0

    		distance = dis if dis.abs < distance.abs

    		bi += 1 if dis < 0
    		ci -= 1 if dis > 0
    	end
    end

    target + distance
end


nums = [1, 3, 5, 7, 9]