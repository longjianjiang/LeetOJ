# @param {Integer[]} height
# @return {Integer}


# 根据一组数据构建一幅条状图，求改条状图中面积最大的矩形
# 很直观的想到两次遍历，然后计算最大面积
# 但是提交显示超时了，所以得换种更高效的方法


def max_area_timeout(height)
    return 0 if height.count < 2
    return height.min if height.count == 2

    total = height.count
    max = 0

    for i in 0...total
    	next_idx = i + 1

    	if next_idx < total - 1
    		for j in next_idx...total
	    		h = height[j] < height[i] ? height[j] : height[i]
	    		w = j - i
	    		area = w * h
	    		max = area > max ? area : max
    	    end
    	end

    end

    return max
end


# 另一种方法，创建左右两边指针分别指向第一个和最后一个
# while(left < right) 循环，当左边低，则left++， 当左边高则right--， 依次计算面积，最好得出最大


def max_area(height)
	left, right = 0, height.count - 1

	max = 0

	while left < right
		if height[left] < height[right]
			area = (right - left) * height[left]
			left += 1
		else
			area = (right - left) * height[right]
			right -= 1
		end

		max = area if area > max
	end

	max
end

height = [1,8,6,2,5,4,8,3,7]
puts max_area(height)
