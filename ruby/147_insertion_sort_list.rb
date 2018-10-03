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
# Input: 4->2->1->3
# Output: 1->2->3->4

# 使用插入排序给链表中的val进行排序
# 插入排序的思路，首先假定第一个元素是有序的，每次从剩下的元素中取一个放入有序列表中，直到剩下的元素为空。

def insertion_sort_list(head)
    return head if head.nil? || head.next.nil?

    unorder_list = head.next
    head.next = nil

    while unorder_list
        node = unorder_list
        unorder_list = unorder_list.next
        node.next = nil

        if node.val < head.val 
            node.next = head
            head = node
        else
            p = head
            while p.next && node.val >= p.next.val 
                p = p.next
            end

            node.next = p.next
            p.next = node
        end
    end 
    
    head
end

# 另一种思路，新建一个链表，遍历原链表，按大小依次插入到新链表，直到原链表为空

def insertion_sort_list_version2(head)
    node, cur = ListNode.new(-1), nil

    while head
        tmp = head.next

        cur = node
        while cur.next && cur.next.val <= head.val
            cur = cur.next
        end

        head.next = cur.next
        cur.next = head
        head = tmp
    end

    node.next
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

l1 = ListNode.new(1, ListNode.new(4, ListNode.new(3, ListNode.new(5, ListNode.new(7, ListNode.new(2, nil))))))
l2 = insertion_sort_list_version2(l1)

puts show_list_node_val(l2)
