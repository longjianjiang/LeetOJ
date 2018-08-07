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


# 合并两个有序链表，一个直觉的思路：
# 依次比较两个链表的节点val大小，将其存放进新链表，同时移除源链表中该节点，直到某个链表为空，此时新链表指向不为空的链表即可

def merge_two_lists(l1, l2)
	return l1 || l2 unless l1 && l2

	l1, l2 = l2, l1 if l1.val > l2.val
	l3, l1 = l1, l1.next

	node = l3
	while l1 && l2
		if l1.val < l2.val
			node.next = l1
			l1 = l1.next
		else 
			node.next = l2
			l2 = l2.next
		end

		node = node.next
	end

	node.next = l1 || l2

	l3
end


# 也可以使用递归的方式
def merge_two_lists_use_recursion(l1, l2)
	return l1 || l2 unless l1 && l2

	if l1.val <= l2.val
		l1.next = merge_two_lists_use_recursion(l1.next, l2)
		return l1
	else
		l2.next = merge_two_lists_use_recursion(l1, l2.next)
		return l2
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

l1 = ListNode.new(1, ListNode.new(2, ListNode.new(4, nil)))
l2 = ListNode.new(1, ListNode.new(3, ListNode.new(4, nil)))

l3 = merge_two_lists(ListNode.new(1), ListNode.new(2))

puts show_list_node_val(l3)