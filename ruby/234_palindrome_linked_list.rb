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

# 判断链表是否为回文，判断回文使用头尾指针，不过因为是链表，我们可以使用判断两边是否相等来判断
# 首先找到链表中间节点，将其倒置，然后将其与head一一对比即可
# 1-2-2-1 	=> middle=2 => 1-2-nil, 1-2-nil
# 1-1-3-1-1	=> middle=3 => 1-1-3-nil, 1-1-3-nil


def is_palindrome(head)
	return true if head.nil? || head.next.nil?

	slow, fast = head, head
	while fast && fast.next
		slow = slow.next
		fast = fast.next.next
	end

	reverse = reverse_list(slow)

	puts show_list_node_val(reverse)
	puts show_list_node_val(head)

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

l1 = ListNode.new(1, ListNode.new(1, ListNode.new(3, ListNode.new(1, ListNode.new(1,nil)))))

puts is_palindrome(l1)
