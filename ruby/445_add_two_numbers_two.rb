# Definition for singly-linked list.
class ListNode
    attr_accessor :val, :next
    def initialize(val, nextNode=nil)
        @val = val
        @next = nextNode
    end
end

# @param {ListNode} l1
# @param {ListNode} l2
# @return {ListNode}

# Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
# Output: 7 -> 8 -> 0 -> 7

# 本题和之前的一题类似，只是本题的链表是高位开头，简单点将两个链表倒置，其实就和之前一题一样了，依次从低位相加，注意进位即可
# 所以一种思路就是利用栈，将链表入栈，然后出栈依次低位相加即可

def add_two_numbers(l1, l2)
    stack_one, stack_two = Array.new, Array.new

    while l1
    	stack_one.push(l1.val)
    	l1 = l1.next
    end
    while l2
    	stack_two.push(l2.val)
    	l2 = l2.next
    end

    node = ListNode.new(0)

    sum = 0
    while !stack_one.empty? || !stack_two.empty?
    	sum += stack_one.pop if !stack_one.empty?
    	sum += stack_two.pop if !stack_two.empty?

    	node.val = sum % 10
    	head = ListNode.new(sum / 10)
    	head.next = node
    	node = head

    	sum /= 10
    end

    return node.val == 0 ? node.next : node
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

l1 = ListNode.new(7, ListNode.new(2, ListNode.new(4, ListNode.new(3))))
l2 = ListNode.new(5, ListNode.new(6, ListNode.new(4)))

l3 = add_two_numbers(l1, l2)

puts show_list_node_val(l3)