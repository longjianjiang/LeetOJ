# Definition for singly-linked list.
# class ListNode
#     attr_accessor :val, :next
#     def initialize(val)
#         @val = val
#         @next = nil
#     end
# end

# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {ListNode} head
# @return {TreeNode}

# 给定一个有序的链表，构建一个二分查找树
# 思路和处理数组类似, 首先当链表为空或者只有一个节点时返回nil，或者只有一个根节点
# 使用快慢指针找到中点，同时记录中点的前一个节点，需要将其指向nil，以中点为界，将链表拆分
# 以中点为根节点创建树，然后用拆分出来的链表递归的创建子树即可

def sorted_list_to_bst(head)
    return nil if head.nil?
    return TreeNode.new(head.val) if head.next.nil?

    slow, fast = head, head
    node = nil
    while fast && fast.next
        node = slow
        slow = slow.next
        fast = fast.next.next
    end

    node.next = nil

    tree = TreeNode.new(slow.val)
    tree.left = sorted_list_to_bst(head)
    tree.right = sorted_list_to_bst(slow.next)

    return tree
end