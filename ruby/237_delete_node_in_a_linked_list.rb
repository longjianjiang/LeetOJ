# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} node
# @return {Void} Do not return anything, modify node in-place instead.


# Input: head = [4,5,1,9], node = 1
# Output: [4,5,9]
# Explanation: You are given the third node with value 1, the linked list
#              should become 4 -> 5 -> 9 after calling your function.


# 删除链表中给定的节点node， 本题只给了需要删除的node，
# 之前删除链表中节点，我们都是定位到需要删除节点的前一个节点，将其指向需要删除节点的下一个节点
# 本题中只给了需要删除的节点，所以我们可以先将此节点的val设置为节点下一个的val，然后将其指向节点的next.next, 这样也就实现了删除这个节点
	
def delete_node(node)
    node.val = node.next.val 
    tmp = node.next
    node.next = tmp.next
end