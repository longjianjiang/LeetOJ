# @param {Integer[]} nums
# @return {Integer}

# Given nums = [1,1,1,2,2,3],
# Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
# It doesn't matter what you leave beyond the returned length.

def remove_duplicates(nums)
    return 0 if nums.empty?

    res = 1
    for i in 1...nums.size
        if nums[i] > nums[i-1]
            res += 1
        else 
            i += 1
        end
    end     

    res
end

nums = [1,1,1,2,2,3]
puts remove_duplicates(nums)