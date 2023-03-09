function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}

var addTwoNumbers = function(l1, l2) {
    return addTwoNumbersWithCarry(l1, l2, 0);
};

var addTwoNumbersWithCarry = function(l1, l2, carry) {
    if (!l1 && !l2 && !carry) {
        return null;
    }

    let num1 = 0;
    if (l1) {
        num1 = l1.val;
        l1 = l1.next;
    }

    let num2 = 0;
    if (l2) {
        num2 = l2.val;
        l2 = l2.next;
    }

    let s = (num1 + num2 + carry) % 10;
    let c = Math.floor((num1 + num2 + carry) / 10);

    return new ListNode(s, addTwoNumbersWithCarry(l1, l2, c));
};

var l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
var l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

console.log(addTwoNumbers(l1, l2));