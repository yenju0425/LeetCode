class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1, l2):
        l1_val = 0 if l1 == None else l1.val
        l2_val = 0 if l2 == None else l2.val

        l1_next = None if l1 == None else l1.next
        l2_next = None if l2 == None else l2.next

        div, mod = divmod(l1_val + l2_val, 10)
        node = ListNode(mod)
        if div != 0 or l1_next != None or l2_next != None:
            if l1_next == None:
                newNode = ListNode(div)
                l1_next = newNode
            else:
                l1_next.val = l1_next.val + div

            node.next = self.addTwoNumbers(l1_next, l2_next)

        return node

S = Solution()

#inputs
n2 = ListNode(9)
n1 = ListNode(9, n2)
n0 = ListNode(9, n1)

m1 = ListNode(9)
m0 = ListNode(9, m1)

result = S.addTwoNumbers(n0, m0)

while result != None:
    print(result.val, ' ')
    result = result.next

