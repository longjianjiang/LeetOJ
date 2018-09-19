# Definition for singly-linked list.
class ListNode
    attr_accessor :val, :next
    def initialize(val, nextNode=nil)
        @val = val
        @next = nextNode
    end
end

# @param {ListNode} head
# @return {Boolean}

# 判断链表中val是否为回文

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

def is_palindrome(head)
    
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

l1 = ListNode.new(1, ListNode.new(2, ListNode.new(4, nil)))
l2 = reverse_list(l1)

puts show_list_node_val(l1)
puts show_list_node_val(l2)