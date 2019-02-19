# @param {Integer[]} arr
# @param {Integer} k
# @param {Integer} x
# @return {Integer[]}

# 给定有序数组，要求返回k个最接近x的元素，以升序的形式返回，如果两个元素距离x相等，返回较小的那个

# 根据题意我们需要返回的是原数组的子数组，所以我们从两边开始剔除元素，当长度等于k返回即可

def find_closest_elements_1(arr, k, x)
    res = arr
    while res.size() > k 
        if x - arr.first <= arr.last - x
            arr.pop
        else
            arr.delete_at(0)
        end
    end 
    
    res
end

# 查找肯定要尝试二分，所以本题也可以使用二分，思路还是类似的，返回原数组的子数组，通过二分我们可以确定截取的左右边界
# 所以需要先找到数组中最后一个小于等于x的元素的下标idx，right指向idx，left指向idx-1
# 然后移动left，right下标，注意距离相等时，优先返回小的，也就是左边的，最后返回 [left, right)区间即可

def find_closest_elements_2(arr, k, x)
    left, right = 0, arr.size()-1
    while left <= right
        mid = left + (right - left) / 2
        if arr[mid] > x 
            right = mid - 1
        else
            left = mid + 1
        end
    end

    right = 1 if right < 0
    left = right - 1

    k.times do
        if left >= 0 && right < arr.size()
            if x - arr[left] <= arr[right] - x
                left -= 1
            else
                right += 1
            end
        elsif left >= 0
            left -= 1
        else
            right += 1
        end
    end

    arr[left+1...right]
end

# 二分查找，返回最后一个小于等于target的下标

def bsearch_3(lists, target)
    left, right = 0, lists.length
    while left < right
        mid = left + (right-left) / 2
        if lists[mid] <= target
            left = mid+1
        else
            right = mid
        end
    end

    right-1
end

def bsearch_4(arr, target)
    left, right = 0, arr.length-1
    while left <= right
        mid = left + (right - left) / 2
        if arr[mid] > target
            right = mid - 1
        else
            left = mid + 1
        end
    end

    right
end

# arr = [1, 2, 3]
# puts arr[0...2]
# arr.delete_at(0)
# puts arr.first
# puts arr.last

puts bsearch_3([3, 5, 6, 8, 9, 10], 7)
puts bsearch_4([3, 5, 6, 8, 9, 10], 7)

puts bsearch_3([0, 1, 1, 1, 1, 1], -1)
puts bsearch_4([0, 1, 1, 1, 1, 1], -1)