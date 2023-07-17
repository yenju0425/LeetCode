class ListNode {
    val: number
    next: ListNode | null
    constructor(val?: number, next?: ListNode | null) {
        this.val = (val===undefined ? 0 : val)
        this.next = (next===undefined ? null : next)
    }
}

function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
  const l1_stack: number[] = [];
  const l2_stack: number[] = [];

  while (l1 != null) {
    l1_stack.push(l1.val);
    l1 = l1.next;
  }

  while (l2 != null) {
    l2_stack.push(l2.val);
    l2 = l2.next;
  }

  let node: ListNode | null = null;
  let val: number = 0;
  while (l1_stack.length != 0 || l2_stack.length != 0 || val != 0) {
    val = (l1_stack.pop() || 0) + (l2_stack.pop() || 0) + val;
    node = new ListNode(val % 10, node);
    val = Math.floor(val / 10);
  }

  return node;
};

// generate test cases (linked lists)
const l1 = new ListNode(7, new ListNode(2, new ListNode(4, new ListNode(3))));
const l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

// print test cases
let result = addTwoNumbers(l1, l2);
while (result != null) {
  console.log(result.val);
  result = result.next;
}