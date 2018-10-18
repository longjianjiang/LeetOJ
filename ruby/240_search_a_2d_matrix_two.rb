# @param {Integer[][]} matrix
# @param {Integer} target
# @return {Boolean}


# 给定二维数组，数组每行从左往右是升序，每列从上到下也是升序
# 我们可以从左下角的数为起点，进行查找，这样每次[x][y] 正好是二维数组中的一个元素，循环遍历即可

def search_matrix(matrix, target)
    return false if matrix.empty? || matrix[0].empty?

    x, y = matrix.size-1, 0
    while x >= 0 && y < matrix[0].size
    	case matrix[x][y] <=> target
    	when 0
    		return true
    	when 1
    		x -= 1
    	when -1
    		y += 1
    	end
    end

    return false
end

matrix = [[-1,3]]

puts search_matrix(matrix, 3)