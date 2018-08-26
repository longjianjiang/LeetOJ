# @param {String} haystack
# @param {String} needle
# @return {Integer}


# 实现字符串的`indexOf`方法

def str_str(haystack, needle)
	return 0 if needle.size == 0
	return -1 if needle.size > haystack.size

    cursor = -1
    m = haystack.size
    n = needle.size

    for i in 0..m-n
    	if haystack[i] == needle[0]
    		cursor = i 
    		for j in 1...n
    			if needle[j] != haystack[i+j]
    				cursor = -1
    				break
    			end
    		end

    		if cursor != -1
    			return cursor
    		end
    	end
    end

    cursor
end


def str_str_version2(haystack, needle)
	return 0 if needle.size == 0
	return -1 if needle.size > haystack.size

	cursor = 0
	while cursor <= haystack.size - needle.size
		return cursor if haystack[cursor, needle.size] == needle
		cursor += 1
	end

	-1
end

haystack = "aaaaa"
needle   = "bba"

puts str_str(haystack, needle)
