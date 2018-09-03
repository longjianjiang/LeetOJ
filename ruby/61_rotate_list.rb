# Definition for singly-linked list.
class ListNode
    attr_accessor :val, :next
    def initialize(val, nextNode=nil)
        @val = val
        @next = nextNode
    end
end

# @param {ListNode} head
# @param {Integer} k
# @return {ListNode}


# Input: 0->1->2->NULL, k = 4
# Output: 2->0->1->NULL
# Explanation:
# rotate 1 steps to the right: 2->0->1->NULL
# rotate 2 steps to the right: 1->2->0->NULL
# rotate 3 steps to the right: 0->1->2->NULL
# rotate 4 steps to the right: 2->0->1->NULL


# 给定一个链表和k，按k将链表分为两部分倒置
# 可以按k将链表拆分位2份，一份为倒置在前面的后k个list1；另一份则为前面len-k个list2；
# 所以首先求出链表长度及尾节点，然后定位到前一份len-k个节点的最后一个
# 此时将list2 拼在 list1 后面即可

def get_list_length(head, tail)
	# ruby 函数引用传递
	len = 0
	while head
		len += 1
		tail = head
		head = head.next
	end

	len
end


def rotate_right(head, k)
	node = head
	len, tail = 0, head
	while node
		len += 1
		tail = node
		node = node.next 
	end

	return head if len < 2

	k = k % len
	n = len - k
	p = head
	for i in 1...n
		p = p.next
	end

	tail.next = head
	head = p.next
	p.next = nil

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


l1 = ListNode.new(0, ListNode.new(1, ListNode.new(2, nil)))

l2 = rotate_right(l1, 1)

