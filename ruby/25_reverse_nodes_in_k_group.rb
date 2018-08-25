# Definition for singly-linked list.
class ListNode
    attr_accessor :val, :next
    def initialize(val, nextNode=nil)
        @val = val
        @next = nextNode
    end
end


# 	  For example:
#     Given this linked list: 1 -> 2 -> 3 -> 4 -> 5
#     For k = 2, you should return: 2 -> 1 -> 4 -> 3 -> 5
#     For k = 3, you should return: 3 -> 2 -> 1 -> 4 -> 5

# @param {ListNode} head
# @param {Integer} k
# @return {ListNode}


# 给定链表，和k，要求将链表进行分为k组，组内元素进行倒置，分组不足k时保留原样
# 思路： 新建链表，首先找到前k个倒置存入链表，继续之前操作，最后剩下的放在最后即可。

def reverse_k_group(head, k)
	return head if (k -= 1) == 0

	node = ListNode.new(0, nil)
	last = node

	fast, slow = head, head
	while fast
		k.times {fast && fast = fast.next}
		break if fast.nil?

		curr, prev = slow, nil
		while prev != fast
			curr_next = curr.next
			curr.next = prev
			prev = curr
			curr = curr_next
		end

		last.next = fast
		last = slow

		fast, slow = curr, curr
	end
	last.next = slow

	node.next
end



def reverse_node(node)
	return node if node.nil?

	curr, prev = node, nil
	while curr
		curr_next = curr.next
		curr.next = prev
		prev = curr
		curr = curr_next
	end

	prev
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

l1 = ListNode.new(1, ListNode.new(2, ListNode.new(3, ListNode.new(4, ListNode.new(5, nil)))))


l11 = ListNode.new(1, ListNode.new(2, nil))
l12 = ListNode.new(3, ListNode.new(4, nil))
l13 = ListNode.new(5, ListNode.new(6, nil))

l11 = l12
l11 = l13

puts show_list_node_val(l12)