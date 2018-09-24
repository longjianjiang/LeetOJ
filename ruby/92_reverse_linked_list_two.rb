# Definition for singly-linked list.
class ListNode
    attr_accessor :val, :next
    def initialize(val, nextNode=nil)
        @val = val
        @next = nextNode
    end
end

# @param {ListNode} head
# @param {Integer} m
# @param {Integer} n
# @return {ListNode}

# 1 ≤ m ≤ n ≤ length of list.
# Input: 1->2->3->4->5->NULL, m = 2, n = 4
# Output: 1->4->3->2->5->NULL

# 给定区间反转链表
# 思路遍历一次，将区间的节点倒置，然后拼接到原链表中即可
# 我们新建一个list，next指向head，这样更改head，最后返回结果可以直接返回list.next即可
# 首先找到需要反转的头节点，记做cur；用一个pre指向cur，以上述输入为例，pre指向1这个节点，同时用last指向cur.next节点，最后需要用last指向最后节点
# 然后循环3次，也就是（n-m+1）次，每执行一次倒置一次，也就是前面的节点不断往后存放，达到倒置的目的
# 区间中的节点倒置完成后，cur执行pre.next, 也就是原链表中最后的节点； 最后将区间插入即可

def reverse_between(head, m, n)
	node = ListNode.new(-1)
	node.next = head
	cur = node
	(m-1).times do 
		cur = cur.next
	end

	reverse, pre, last = nil, cur, cur.next
	(n-m+1).times do
		cur = pre.next
		pre.next = cur.next
		cur.next = reverse
		reverse = cur
	end

	cur = pre.next
	pre.next = reverse
	last.next = cur

	node.next
end


# 用四个节点记录区间节点以及他们的前一个和后一个
# 将区间倒置，然后拼接到前一个和后一个即可

def reverse_between_version2(head, m, n)
	return head if head.nil? || n<=m

	start, prev = nil, nil
	last, tail = nil, nil

	p, k = head, 1
	while p && k <= n
		if k == m-1
			prev = p
			start = p.next
		end

		if k == n
			last = p 
			tail = p.next
		end

		p = p.next
		k += 1
	end

	if prev.nil?
		start = head
	end

	# n 大于链表长度
	if last.nil?
		return head
	end

	p = start
	last.next = nil
	q = reverse(start)

	if prev
		prev.next = q
	else
		head = last
	end

	p.next = tail

	head
end

def reverse(head)
	p, q = nil, nil
	while head
		p = head
		head = head.next
		p.next = q 
		q = p 
	end

	q
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

l1 = ListNode.new(1, ListNode.new(2, ListNode.new(3, ListNode.new(4, ListNode.new(5,nil)))))
l3 = reverse_between(l1, 1, 4)
puts show_list_node_val(l3)

