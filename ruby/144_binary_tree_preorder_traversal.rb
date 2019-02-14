# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {Integer[]}

# 给定二叉树，给出先序遍历结果的数组
# 使用栈进行非递归的遍历即可

def preorder_traversal(root)
    return [] if root.nil?
    stack, res = Array.new(), Array.new()
    stack.push(root)
    while stack.length() > 0
        cur = stack.pop()
        res.push(cur.val)
        stack.push(cur.right) if cur.right
        stack.push(cur.left) if cur.left
    end

    res
end