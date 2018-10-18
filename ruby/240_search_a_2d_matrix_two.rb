# @param {Integer[][]} matrix
# @param {Integer} target
# @return {Boolean}


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