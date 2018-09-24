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


def append_list(left, right, node, vars)
	if head.nil?
		eval "left = node", vars
		eval "right = node", vars
		# head, tail = node, node
	else
		eval "right.next = node", vars
		eval "right = node", vars
		# tail.next = node
		# tail = node
	end
end


def partition(head, x)
    return head if head.nil? || head.next.nil?

    left, right = nil, nil

    while head && head.val < x
    	node = head
    	head = head.next
    	node.next = nil
    	append_list(left, right, node, binding)
    end

    if head
    	p = head
    	while p.next
    		if p.next.val < x
    			node = p.next
    			p.next = node.next
    			node.next = nil
    			append_list(left, right, node, binding)
    		else
    			p = p.next
    		end
    	end
    end

    append_list(left, right, node, binding)

    left
end


# 思路一样，之前那种方法初始化为nil，所以导致了判断是否为nil
# 所以此时可以换种思路，初始化Nodeval为-1，返回的时候，返回next即可，这样即可省去之前的判断

def partition_version_2(head, x)
	return head if head.nil? || head.next.nil?

	left, right = ListNode.new(-1), ListNode.new(-1)
	left.next = head

	p, q = left, right
	while p.next
		if p.next.val < x
			q.next = p.next
			q = q.next
			p.next = p.next.next
			q.next = nil
		else
			p = p.next
		end
	end

	q.next = left.next

	right.next
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
l2 = partition_version_2(l1, 3)
puts show_list_node_val(l2)


def swap(a, b, vars)
	tmp = a
	eval "a = b", vars
	eval "b = #{tmp}", vars
end

def swap(a, b)
	a, b = b, a 
end

# a, b = 5, 7
# swap(a, b, binding)
# puts "a = #{a}, b = #{b}"