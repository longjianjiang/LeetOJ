# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode[]} lists
# @return {ListNode}


# 合并多个链表，之前一道题是合并2个链表，所以自然想到递归，将多个最终转换为合并两个链表的情况
def merge_k_lists(lists)
	_merge_k_lists_(lists, 0, lists.size-1)
end

private def _merge_k_lists_(lists, left, right)
     return lists[left] unless right - left > 0

     mid = (left + right) / 2
     l = _merge_k_lists_(lists, left, mid)
     r = _merge_k_lists_(lists, mid + 1, right)
     return _merge_two_lists_(l, r)
end

private def _merge_two_lists_(l1, l2)
	return l1 || l2 unless l1 && l2

	l1, l2 = l2, l1 if l1.val > l2.val
	l3, l1 = l1, l1.next

	node = l3
	while l1 && l2
		if l1.val < l2.val
			node.next = l1
			l1 = l1.next
		else 
			node.next = l2
			l2 = l2.next
		end

		node = node.next
	end

	node.next = l1 || l2

	l3
end

