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

# Input: 1->2->3->3->4->4->5
# Output: 1->2->5
# Input: 1->1->1->2->3
# Output: 2->3

# 给定链表，删除重复元素，不留一个

def delete_duplicates(head)
    return head if head == nil || head.next == nil

    if head.val == head.next.val
        num = head.val 
        while head && head.val == num
            head = head.next
        end 
        return delete_duplicates(head)
    else
        head.next = delete_duplicates(head.next)
        return head
    end
end

def delete_duplicates_version2(head)
    return head if head == nil || head.next == nil

    p, q = nil, head
    while q && q.next
        if q.val == q.next.val
            p = q

            while q.next && q.val == q.next.val
                q = q.next
            end

            if p == head
                head = q.next
            else
                node = head
                while node.next != p
                    node = node.next
                end 
                node.next = q.next
            end 
        end

        q = q.next
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

l1 = ListNode.new(1, ListNode.new(1, ListNode.new(2, nil)))

l2 = delete_duplicates(l1)

puts show_list_node_val(l2)