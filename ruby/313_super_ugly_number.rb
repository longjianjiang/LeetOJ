# @param {Integer} n
# @param {Integer[]} primes
# @return {Integer}

# 和264类似，只是本题质数因子是一个数组，我们只需要建立一个len 的idx 数组即可。

def nth_super_ugly_number(n, primes)
    res, idxs = Array.new(1,1), Array.new(primes.length, 0)

    while res.length < n
    	idx_number_list = Array.new(primes.length, 0)

    	for i in 0...primes.length
    		idx_number_list[i] = res[idxs[i]] * primes[i]
    	end

    	min_number = idx_number_list.min

    	for i in 0...primes.length 
    		idxs[i] += 1 if idx_number_list[i] == min_number
    	end

    	res.push(min_number)
    end

    res.last
end