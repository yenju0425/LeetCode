class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1, l2):
        v1 = 0 if l1 == None else l1.val
        v2 = 0 if l2 == None else l2.val

        l1 = l1.next if l1 != None else l1
        l2 = l2.next if l2 != None else l2

        div, mod = divmod(v1 + v2, 10)
        node = ListNode(mod)
        if div != 0 or l1 != None or l2 != None:
            if l1 == None:
                l1 = ListNode(div)
            else:
                l1.val = l1.val + div

            node.next = self.addTwoNumbers(l1, l2)

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

