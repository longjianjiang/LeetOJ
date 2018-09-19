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
# 首先利用快慢指针找到另一边的head，将其反转记做 `reverse`，
# 然后head 和 reverse进行比较val即可

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
	return true if head.nil? || head.next.nil?

	slow, fast = head, head
	while fast.next && fast.next.next
		slow = slow.next
		fast = fast.next.next
	end

	# slow.next 就是右边的head
	reverse = reverse_list(slow.next)

	while reverse
		return false if head.val != reverse.val
		head = head.next
		reverse = reverse.next
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
