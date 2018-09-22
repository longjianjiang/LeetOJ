# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @return {ListNode}

# 求链表的中间节点，如果偶数，取后一个
# 使用两个指针即可，到快指针走完，慢指针就是中间节点

def middle_node(head)
	slow, fast = head, head

	while fast && fast.next
		slow = slow.next
		fast = fast.next.next
	end

	slow
end