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

# Input: -1->5->3->4->0
# Output: -1->0->3->4->5

# 给链表排序，要求 O(n log n)
# 所以排序只能使用快速排序，归并排序，不过链表更适合归并排序
# 所以思路将链表使用快慢指针分割，递归，最后合并排序好的链表即可


def merge_list(l1, l2)
    return l1 || l2 unless l1 && l2

    if l1.val <= l2.val
        l1.next = merge_list(l1.next, l2)
        return l1
    else 
        l2.next = merge_list(l2.next, l1)
        return l2
    end
end


def sort_list(head)
    return head if head.nil? || head.next.nil?

    prev = nil
    slow, fast = head, head
    while fast && fast.next
        prev = slow
        slow = slow.next
        fast = fast.next.next
    end 

    prev.next = nil

    l1 = sort_list(head)
    l2 = sort_list(slow)

    merge_list(l1, l2)
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

l1 = ListNode.new(1, ListNode.new(3, ListNode.new(2, ListNode.new(5, nil))))