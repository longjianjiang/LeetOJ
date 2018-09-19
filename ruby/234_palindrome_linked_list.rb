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

# Input: 1->2->2->1
# Output: true

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
	len = 0
	tail = head
	while tail
		len += 1
		tail = tail.next
	end 

	return true if len <= 1
	
	if len == 2
		return head.val == head.next.val
	end 

	if len == 3 
		return head.val == head.next.next.val
	end

	slow, fast = head, head
	while fast.next && fast.next.next
		slow = slow.next
		fast = fast.next.next
	end

	# fast = slow.next if fast.next == nil

	reverse = reverse_list(slow.next)

	while len > 0
		return false if head.val != reverse.val
		head = head.next
		reverse = reverse.next
		len -= 1
	end

	return true
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

l1 = ListNode.new(1, ListNode.new(1, ListNode.new(2, ListNode.new(1, nil))))

puts is_palindrome(l1)