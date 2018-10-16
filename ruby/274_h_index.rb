# @param {Integer[]} citations
# @return {Integer}

# Input: citations = [3,0,6,1,5]
# Output: 3 
# Explanation: [3,0,6,1,5] means the researcher has 5 papers in total and each of them had 
#              received 3, 0, 6, 1, 5 citations respectively. 
#              Since the researcher has 3 papers with at least 3 citations each and the remaining 
#              two with no more than 3 citations each, her h-index is 3.

# 给定一个数组，论文引用数量数组，求h-index，假设引用n为3，说明有3篇论文引用次数大于等于3。

def h_index(citations)
    f = ->(a, b) { b <=> a }
    citations.sort(&f).each_with_index do |item, idx|
    	return idx if idx >= item
    end
    citations.size
end

# 首先将数组排序（升序），然后遍历数组，取[len-idx, [idx]] 中的min，然后和res中取大的
def h_indx_version2(citations)
	res = 0
	citations.sort.each_with_index do |item, idx|
		res = [res, [citations.size-idx, item].min].max
	end

	res
end


nums = [9,0,7,1,5]
puts h_index(nums)
