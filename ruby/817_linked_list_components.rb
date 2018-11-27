# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# @param {ListNode} head
# @param {Integer[]} g
# @return {Integer}

# 给定一个链表和一个数组，数组中的元素是链表中的部分节点的元素组成，让我们给定一个count，要求是链表的某一段而且节点的数字存在于数组中
# 笔者开始没有理解题目意思，后来看了别人的解释才有所理解，也就是求链表子串的个数，只不过这个子串的val得存在于数组中

# 遍历数组，当节点的val存在数组时继续，直到不存在，相等于得到了前面一段连续的子串，将count加1；
# 此时将节点往前移动一次，如果不为空，因为此时的节点的val不在数组中；重复之前的步骤直到链表为空

def num_components(head, g)
    res = 0
    while head
        count = 0
        while head && g.include?(head.val)
            count += 1
            head = head.next
        end
        
        res += 1 if count > 0
        
        head = head.next if head
    end
    res
end