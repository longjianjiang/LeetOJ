# Definition for singly-linked list.
class ListNode
    attr_accessor :val, :next
    def initialize(val, nextNode=nil)
        @val = val
        @next = nextNode
    end
end

# @param {ListNode} head
# @return {Void} Do not return anything, modify head in-place instead.

# Given a singly linked list L: L0→L1→…→Ln-1→Ln,
# reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
# Given 1->2->3->4, reorder it to 1->4->2->3.
# Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

# 给定链表按照规则重新组装
# 首先找到链表的中间节点，将链表拆分为两段，将后一段倒置
# 然后依次插入到前一段，直到前一段为空即可

def reverse_list(head)
	left, right = nil, nil
	while head
		left = head
		head = head.next
		left.next = right
		right = left
	end

	right
end


def reorder_list(head)
    return if head.nil? || head.next.nil? || head.next.next.nil?

    slow, fast = head, head
    list_one_head, list_one_tail = head, nil
    while fast && fast.next
    	list_one_tail = slow
    	slow = slow.next
    	fast = fast.next.next
    end

    list_one_tail.next = nil
    list_two_head = reverse_list(slow)

    node = head
    while node
    	list_one_next = node.next
    	list_two_next = list_two_head.next

    	node.next = list_two_head
    	if list_one_next.nil?
    		return
    	else
    		list_two_head.next = list_one_next
    	end
    	
    	node = list_one_next
    	list_two_head = list_two_next
    end
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

l1 = ListNode.new(1, ListNode.new(2, ListNode.new(3, ListNode.new(4, nil))))
reorder_list(l1)

puts show_list_node_val(l1)
