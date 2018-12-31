# @param {Integer} n
# @return {Integer}

# 本题是263的扩展，给定n让我们给出所谓 ugly number 数组中第n个 ugly number
# 题目给了一些提示，也就是我们如果得到ugly number 数组，那么求第n个就十分简单了，
# 怎么取到ugly number 数组，所谓ugly number 就是ugly number 乘 2 3 5 产生的数字，
# 所以题目提示使用合并三个有序链表的思路, 每次取最小的，建立ugly number 数组。

def nth_ugly_number(n)
    res = Array.new(1,1)
    idx2, idx3, idx5 = 0, 0, 0
    while res.length < n
    	number2, number3, number5 = res[idx2] * 2, res[idx3] * 3, res[idx5] * 5
    	minNumber = [number2, number3, number5].min
    	idx2 += 1 if minNumber == number2
    	idx3 += 1 if minNumber == number3
    	idx5 += 1 if minNumber == number5
    	res.push(minNumber)
    end

    res.last
end
