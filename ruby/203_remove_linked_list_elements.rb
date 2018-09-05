# Definition for singly-linked list.
class ListNode
    attr_accessor :val, :next
    def initialize(val, nextNode=nil)
        @val = val
        @next = nextNode
    end
end


# @param {ListNode} head
# @param {Integer} val
# @return {ListNode}

# Input:  1->2->6->3->4->5->6, val = 6
# Output: 1->2->3->4->5

def remove_elements(head, val)
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

l1 = ListNode.new(1, ListNode.new(1, ListNode.new(2, nil)))
