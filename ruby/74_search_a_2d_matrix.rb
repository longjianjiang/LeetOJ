# @param {Integer[][]} matrix
# @param {Integer} target
# @return {Boolean}

# 给定一个二维矩阵，每一行数据是升序的，后一行的首元素大于前一行的尾元素
# 有序查找可以使用二分查找，首先二分找到所在元素的行，然后二分查找所在行即可

def search_matrix(matrix, target)
	return false if matrix.empty? || matrix[0].empty?
    left, right = 0, matrix.size-1
    while left <= right
    	mid = left + (right-left)/2
    	case matrix[mid][0] <=> target
    	when 0
    		return true
    	when 1
    		right = mid-1
    	when -1
    		left = mid+1
    	end
    end

    row = right
    left, right = 0, matrix[row].size-1
    while left <= right
    	mid = left + (right-left)/2
    	case matrix[row][mid] <=> target
    	when 0
    		return true
    	when 1
    		right = mid-1
    	when -1
    		left = mid+1
    	end
    end
    return false
end