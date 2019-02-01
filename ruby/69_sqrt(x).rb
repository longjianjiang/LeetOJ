# @param {Integer} x
# @return {Integer}

# 开平方，只保留整数
# 当x大于1时，二分[1,x], 判断 x / mid 与 mid 大小关系，最后返回 right-1

def my_sqrt(x)
	return x if x <= 1
	left, right = 1, x 
	while left < right
		mid = left + (right - left) / 2
		if x / mid > mid
			left = mid + 1
		elsif x / mid == mid
			return mid
		else
			right = mid
		end
	end

	right-1
end

# @param {Integer[]} lists
# @param {Integer} target
# @return {Integer}
def bsearch(lists, target)
    left, right = 0, lists.length-1
    while left <= right
        mid = left + (right-left) / 2
        if lists[mid] == target
            return mid
        elsif lists[mid] < target
            left = mid+1
        else
            right = mid-1
        end
    end

    -1
end

def bsearch_1(lists, target)
    left, right = 0, lists.length-1
    while left <= right
        mid = left + (right-left) / 2
        if lists[mid] == target
            if mid == 0 || lists[mid-1] != target
                return mid
            else 
                right = mid-1
            end
        elsif lists[mid] < target
            left = mid+1
        else
            right = mid-1
        end
    end

    -1
end

def bsearch_2(lists, target)
    left, right = 0, lists.length-1
    while left <= right
        mid = left + (right-left) / 2
        if lists[mid] >= target
            if mid == 0 || lists[mid-1] < target
                return mid
            else
                right = mid-1
            end
        else
            left = mid+1
        end
    end

    -1
end

# 第一个不小于也就是第一个大于等于 => 最后一个小于target的值
def bsearch_3(lists, target)
    left, right = 0, lists.length
    while left < right
        mid = left + (right-left) / 2
        if lists[mid] < target
            left = mid+1
        else
            right = mid
        end
    end

    right
end



def bsearch_4(lists, target)
    left, right = 0, lists.length-1
    while left <= right
        mid = left + (right-left) / 2
        if lists[mid] <= target
            if mid == lists.length-1 || lists[mid+1] > target
                return mid
            else
                left = mid+1
            end
        else
            right = mid-1
        end
    end

    -1
end

# 第一个大于target的元素 => 查找最后一个小于等于target的元素 => 第一个大于target的元素
# 这样这个元素的前面就是最后一个小于等于target的元素了，所以我们就让left指向这个位置

# 第一个不小于 => 最后一个小于

# 第一个大于 => 最后一个不大于 => 最后一个小于等于
def bsearch_5(lists, target)
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


# lists = [1, 3, 5, 7, 8, 9]
# puts bsearch_2(lists, 2)
# puts bsearch_3(lists, 2)

lists = [3, 5, 6, 8, 9, 10]
puts bsearch_4(lists, 7)
puts bsearch_5(lists, 7)