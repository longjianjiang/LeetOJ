# Definition for singly-linked list.
class ListNode
    attr_accessor :val, :next
    def initialize(val, nextNode=nil)
        @val = val
        @next = nextNode
    end
end

# @param {ListNode} head
# @return {ListNode}

# Input: 1->2->3->4->5->NULL
# Output: 5->4->3->2->1->NULL

# 反转链表
# 使用两个指针，遍历链表，每次添加节点，先添加的在后面，也就是反转的效果

def reverse_list(head)
	left, right = nil, nil
	while head
		left = head
		head = head.next
		left.next = right
		right = left
	end

	right
end

# 使用递归
# 笔者开始看代码没能理解递归的执行步骤，然后断点调试才理解了步骤
# 下面笔者以 1-2-3-nil 为例做个说明

# 1> p = head = 1 (1-2-3-nil)
# 	 head = reverse(2) (2-3-nil)
#    2> p = head = 2 (2-3-nil)
# 		head = reverse(3) = 3
#------------此时递归到最后一个节点，此时head指向尾节点，p指向尾节点前一个----------------------
# `p.next.next = p`    2-3-2-3-2-3-..... （替换位置）
# `p.next = nil`       2-nil             （打破循环）
#------------以上两步进行调换倒数2个节点的位置-------------------------
#       此时head为 3-2-nil, 返回到 1>
#    1> p = head = 1 (1-2-nil)
#       head = 3 (3-2-nil)
#-----------------------------------------------------------------
# `p.next.next = p`    1-2-1-2-1-2-..... （替换位置）
# `p.next = nil`       1-nil         	 （打破循环）
#       此时head为 3-2-1-nil, 链表反转成功

def reverse_list_version2(head)
	return head if head.nil? || head.next.nil?

	p = head
	head = reverse_list_version2(p.next)
	p.next.next = p 
	p.next = nil

	head
end


def show_list_node_val(node)
	str = ""
	while node
		str += node.val.to_s
		node = node.next
		str += '->' if node
	end

	str
end

# 1 2 3 4 5 6
def reverse_print(head)
    return if head.nil?

    if (head.next) 
        reverse_print(head.next)
    end

    puts head.val
end

l1 = ListNode.new(1, ListNode.new(2, ListNode.new(3, ListNode.new(4, ListNode.new(5, ListNode.new(6, nil))))))
reverse_print(l1)
puts "xxxxxx"
l2 = reverse_list_version2(l1)

puts show_list_node_val(l1)
puts show_list_node_val(l2)
