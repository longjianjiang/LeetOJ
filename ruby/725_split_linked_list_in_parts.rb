# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} root
# @param {Integer} k
# @return {ListNode[]}

# Input:  root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
# Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
# Explanation:
# The input has been split into consecutive parts with size difference at most 1,
# and earlier parts are a larger size than the later parts.

# 给定一个链表和一个数字k，让我们将链表拆分成k组，同时要求每组的size长度相差不能超过1，所以可能出现空。
# 还要求前面的子链表的长度要大于等于后面的子链表的长度

def split_list_to_parts(root, k)
    
end