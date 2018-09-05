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

# Input: 1->1->2->3->3
# Output: 1->2->3

# 给定链表要求删除重复元素的节点, 保留其中一个重复的

def delete_duplicates(head)
    return head if head == nil
    p, q = head, head.next
    while p && q
        if p.val != q.val
            p = p.next 
            q = q.next
        else 
            while p.val == q.val 
                q = q.next
                break if q == nil
            end 

            p.next = q
        end
    end 

    head
end

def delete_duplicates_version2(head)
    return head if head == nil

    node = head
    head = head.next
    node.next = nil
    p = node
    q = node

    while head
        if q.val == head.val
            head = head.next
        else
            pos = head
            head = head.next
            pos.next = nil
            q.next = pos
            q = pos
        end
    end

    p
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

l1 = ListNode.new(1, ListNode.new(1, ListNode.new(2, nil)))

l2 = delete_duplicates(l1)

puts show_list_node_val(l2)