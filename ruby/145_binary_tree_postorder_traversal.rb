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

# 后序遍历二叉树
# 使用栈进行非递归遍历即可

def postorder_traversal(root)
    return [] if root.nil?

    stack, res = Array.new(), Array.new()
    pointer = root
    while pointer
        stack.push(pointer)
        pointer = pointer.left
    end

    while stack.length() > 0
        leftVisited, rightVisited = false, false
        if pointer && stack.last().left == pointer
            leftVisited = true
        end
        if pointer && stack.last().right == pointer
            leftVisited = true
            rightVisited = true 
        end 

        pointer = stack.last()

        if pointer.left && !leftVisited
            stack.push(pointer.left)
        elsif pointer.right && !rightVisited
            stack.push(pointer.right)
        else
            res.push(pointer.val)
            stack.pop()
        end
    end

    res
end