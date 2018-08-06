# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @param {Integer} n
# @return {ListNode}

# 给定链表head 和 数字 n， 要求从链表尾部开始删除第n个，返回head
# 因为从尾部删除，所以需要知道链表长度，但是题目要求只能遍历一次，所以可以
# 设置两个节点 (p, q)为head, 假设p在q前面，所以首先根据n，将q前移n次
# 如果此时q.next 为空，则说明此时需要删除的就是链表中的第一个，所以返回head.next 即可
# 如果q.next 不为空，则分别移动p、q, 直到q.next 为空
# 因为之前q先移动了n，所以此时p, q 之间正好差n， 所以 p.next = p.next.next ， 直接删除倒数第n个节点

def remove_nth_from_end(head, n)
    p, q = head, head

    n.times { q = q.next }

    return head.next if q.nil?

    p, q = p.next, q.next while q.next

    p.next = p.next.next

    head
end
