# Definition for singly-linked list.
class ListNode
    attr_accessor :val, :next
    def initialize(val, nextNode=nil)
        @val = val
        @next = nextNode
    end
end

# @param {ListNode} head
# @return {ListNode}


# 给定一个链表，要求交换链表中临近两个节点
# 想到最直观的方法，构造一个链表，指向head，然后依次两两交换临近的节点即可

def swap_pairs(head)
	return head if head.nil? || head.next.nil?

	l = ListNode.new(0)
	l.next = head

	n = l 
	while n.next && n.next.next
		n1, n2, n3 = n, n.next, n.next.next

		n2.next = n3.next
		n3.next = n2
		n1.next = n3

		n = n2
	end

	l.next
end

# 同样也可以使用递归的方式，首先交换链表中头两个节点，然后递归的交换剩下的节点即可
def swap_pairs_version2(head)
	return head if head.nil? || head.next.nil?

	first = head
	second = first.next
	last = second.next

	head = second
	second.next = first
	first.next = swap_pairs_version2(last)

	head
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

l2 = swap_pairs(l1)

puts show_list_node_val(l2)

