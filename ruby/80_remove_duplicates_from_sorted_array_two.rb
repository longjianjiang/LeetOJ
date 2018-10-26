# @param {Integer[]} nums
# @return {Integer}

# Given nums = [1,1,1,2,2,3],
# Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
# It doesn't matter what you leave beyond the returned length.

# 本题和之前的26一样的输入，只是条件不同，之前不能重复，而现在允许重复一次
# 思路还是重新赋值给数组，不过因此允许一个重复，所以新加了sec这个变量来判断间隔是不是大于1，同时当不是数字改变时更新sec

def remove_duplicates(nums)
    return 0 if nums.empty?

    cursor, sec, count = 0, 0, 0
    while cursor < nums.size
        num = nums[cursor]
        cursor += 1
        while (cursor - sec) > 1 && nums[cursor] == num
            cursor += 1
        end

        nums[count] = num
        count += 1
        sec = cursor if num != nums[cursor]
    end  

    count
end

nums =  [1,1,1,2,2,3] #[0,0,1,1,1,1,2,3,3]
puts remove_duplicates(nums)