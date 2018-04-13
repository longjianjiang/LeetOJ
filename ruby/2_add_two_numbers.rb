# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} l1
# @param {ListNode} l2
# @return {ListNode}


def add_two_numbers(l1, l2)
  carry = 0
  notation = 10
  result = nil
  next_node = nil

  while l1 || l2
    unit = carry
    if l1
      unit += l1.val
      l1 = l1.next
    end

    if l2
      unit += l2.val
      l2 = l2.next
    end

    carry = unit / notation
    unit %= notation

    if result
      next_node.next = ListNode.new(unit)
      next_node = next_node.next
    else
      result = ListNode.new(unit)
      next_node = result
    end
  end

  if carry > 0
    next_node.next = ListNode.new(carry)
  end

  result
end
