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

# 中序遍历二叉树
# 使用栈进行非递归遍历即可

def inorder_traversal(root)
    return [] if root.nil?

    stack, res = Array.new(), Array.new()
    pointer = root
    while stack.length() > 0 || pointer
        if pointer
            stack.push(pointer)
            pointer = pointer.left
        else
            pointer = stack.pop()
            res.push(pointer.val)
            pointer = pointer.right
        end
    end

    res
end