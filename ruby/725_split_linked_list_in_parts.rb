# Definition for singly-linked list.
class ListNode
    attr_accessor :val, :next
    def initialize(val, nextNode=nil)
        @val = val
        @next = nextNode
    end
end

# @param {ListNode} root
# @param {Integer} k
# @return {ListNode[]}

# Input:  root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
# Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
# Explanation:
# The input has been split into consecutive parts with size difference at most 1,
# and earlier parts are a larger size than the later parts.

# 给定一个链表和一个数字k，让我们将链表拆分成k组，同时要求每组的size长度相差不能超过1，所以可能出现空。
# 还要求前面的子链表的长度要大于等于后面的子链表的长度

# 首先根据链表长度n和k，n/k, 如果商为0，那么说明每组只有一个节点；
# 如果商大于1，则接下来看余数，余数肯定小于k，将前m组加1个元素，直到余数用完
# 接下来就是拆分链表的事情了

# 具体操作的时候，得注意题目要求的是将链表拆分为k段，所以其实我们求出商m和余数n后
# 循环k次，每次先移动链表m-1次（m-1不能是k-1，因为可能m小于k，或者m大于k），然后看n是否大于0，判断是否继续移动一次
# 此时我们将这段加入链表，原链表也被截短，重复上述操作即可

def get_list_length(list)
    count = 0
    while list
    	count += 1
    	list = list.next
    end	
    count
end

def split_list_to_parts(root, k)
    list_len = get_list_length(root)
    m, n = list_len / k, list_len % k 

    res = Array.new()
    if m == 0
    	while root
    		res.push(ListNode.new(root.val, nil))
    		root = root.next
    	end
    	(k-list_len).times { res.push(nil) }
    else
    	k.times do 
    		node = root
    		(m-1).times { node = node.next }
    		if n > 0
    			node = node.next
    			n -= 1
    		end
    		head = node.next
    		node.next = nil
    		res.push(root)
    		root = head
    	end
    end

    res
end


def show_list_node_val(node)
	str = ""
	while node
		str += node.val.to_s
		node = node.next
		str += '->' if node
	end

	str
end



l1 = ListNode.new(0, ListNode.new(1, ListNode.new(2, nil)))
l2 = ListNode.new(1, ListNode.new(2, ListNode.new(3, ListNode.new(4, ListNode.new(5, ListNode.new(6, ListNode.new(7, ListNode.new(8, ListNode.new(9, ListNode.new(10, nil))))))))))
l3 = ListNode.new(1, ListNode.new(2, ListNode.new(3, ListNode.new(4,ListNode.new(5, ListNode.new(6, ListNode.new(7)))))))
puts split_list_to_parts(l3, 3).inspect
