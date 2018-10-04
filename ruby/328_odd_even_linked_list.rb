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
# Output: 1->3->5->2->4->NULL

# 给定一个链表，让我们按链表节点的奇偶进行组合，奇数节点在前偶数节点在后
# 用两个节点指向头两个奇偶节点（还有一个节点用来记录偶节点的head），然后奇数节点指向偶数节点的next，偶数节点指向奇数节点的next
# 最后将偶数节点放在奇数节点的最后即可


def odd_even_list(head)
    return head if head.nil? || head.next.nil? || head.next.next.nil?
    
    odd, even, even_head = head, head.next, head.next

    while even && even.next
        odd.next = even.next
        odd = odd.next

        even.next = odd.next
        even = even.next
    end

    odd.next = even_head

    head
end

# 另一种思路： 同样使用两个指针，分别指向奇偶节点，每次将偶数节点后的一个奇数节点提前，同时将该提前的奇数节点指向原先奇数节点后的偶数节点
# 同时偶数节点也跳过提前的奇数节点，最后奇偶节点都往前一步, 如下1-2-3-4-5 使用改方法两次遍历即可。

# Input: 1->2->3->4->5->NULL

# <1> 1-3-2-4-5-NULL
# <2> 1-3-5-2-4-NULL


def odd_even_list_version2(head)
    return head if head.nil? || head.next.nil? || head.next.next.nil?

    odd, even = head, head.next

    while even && even.next
        tmp = odd.next

        odd.next = even.next
        even.next = even.next.next
        odd.next.next = tmp

        odd = odd.next
        even = even.next
    end

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

l1 = ListNode.new(1, ListNode.new(2, ListNode.new(3, ListNode.new(4, ListNode.new(5)))))
l2 = odd_even_list_version2(l1)

puts show_list_node_val(l2)