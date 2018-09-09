# Definition for singly-linked list.
class ListNode
    attr_accessor :val, :next
    def initialize(val, nextNode=nil)
        @val = val
        @next = nextNode
    end
end


# @param {ListNode} head
# @param {Integer} val
# @return {ListNode}

# Input:  1->2->6->3->4->5->6, val = 6
# Output: 1->2->3->4->5

# 给定链表，删除链表中val 等于 target的 节点
# 遍历链表，比较每个节点的val ，删除即可

def remove_elements(head, val)

	p, q = head, head
	while p
		if p.val == val
			if p == head
				q = p.next
				head = q
			else
				q.next = p.next
			end
			p = p.next
		else
			q = p
			p = p.next
		end
	end

	head
end

def remove_elements_version2(head, val)
	head = head.next if head && head.val == val 
	return nil if head.nil?

	node = head
	while node.next
		if node.next.val == val 
			node.next = node.next.next
		else
			node = node.next
		end
	end

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

l1 = ListNode.new(1, ListNode.new(2, ListNode.new(2, nil)))

l2 = remove_elements(l1, 2)

puts show_list_node_val(l2)