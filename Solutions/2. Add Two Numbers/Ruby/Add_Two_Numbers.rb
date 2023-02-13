class ListNode
    attr_accessor :val, :next
    def initialize(val = 0, _next = nil)
        @val = val
        @next = _next
    end
end

def add_two_numbers(l1, l2)
    return add_two_numbers_with_carry(l1, l2, false)
end

def add_two_numbers_with_carry(l1, l2, c)
    if (l1 || l2 || c)
        sum = (l1&.val || 0) + (l2&.val || 0) + (c ? 1 : 0)
        return ListNode.new(sum % 10, add_two_numbers_with_carry(l1&.next, l2&.next, sum >= 10))
    end
end

n2 = ListNode.new(9);
n1 = ListNode.new(9, n2)
n0 = ListNode.new(9, n1)

m1 = ListNode.new(9)
m0 = ListNode.new(9, m1)

iter = add_two_numbers(n0, m0)

while iter
    puts iter.val
    iter = iter.next
end