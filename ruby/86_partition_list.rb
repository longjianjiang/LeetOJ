# Definition for singly-linked list.
class ListNode
    attr_accessor :val, :next
    def initialize(val, nextNode=nil)
        @val = val
        @next = nextNode
    end
end


# @param {ListNode} head
# @param {Integer} x
# @return {ListNode}

# Input: head = 1->4->3->2->5->2, x = 3
# Output: 1->2->2->4->3->5

# 划分列表，将小于x的节点放在前面，大于等于x的节点保持原始顺序
# 将原链表中小于x的存到一个新的链表，同时原链表中移除该节点，最后将新链表拼接在原链表之前即可

def partition(head, x)
    return head if head.nil? || head.next.nil?

    left, right = nil, nil

    while head && head.val < x
    	node = head
    	head = head.next
    	node.next = nil
    	append_list(left, right, node)
    end

    puts show_list_node_val(left)
    puts show_list_node_val(right)

    if head
    	p = head
    	while p.next
    		if p.next.val < x
    			node = p.next
    			p.next = node.next
    			node.next = nil
    			append_list(left, right, node)
    		else
    			p = p.next
    		end
    	end
    end

    puts show_list_node_val(head)
    puts show_list_node_val(left)

    append_list(left, right, node)

    left
end


def append_list(head, tail, node)
	if head.nil?
		head, tail = node, node
	else
		tail.next = node
		tail = node
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

l1 = ListNode.new(1, ListNode.new(4, ListNode.new(3, ListNode.new(2, ListNode.new(5, ListNode.new(2, nil))))))
l2 = partition(l1, 3)

puts show_list_node_val(l2)
