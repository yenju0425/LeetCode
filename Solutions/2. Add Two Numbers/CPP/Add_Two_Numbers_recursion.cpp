#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* nxtNode = nullptr;
        ListNode* newNode = nullptr;

        if (l1 != nullptr || l2 != nullptr) {
            int l1_val        = 0;
            int l2_val        = 0;
            ListNode* l1_next = nullptr;
            ListNode* l2_next = nullptr;

            if (l1 != nullptr) {
                l1_val  = l1->val;
                l1_next = l1->next;
            }
            if (l2 != nullptr) {
                l2_val  = l2->val;
                l2_next = l2->next;
            }

            int temp  = l1_val + l2_val;
            int sum   = temp % 10;
            int carry = temp / 10;

            // deal with the carry bit issue
            if (carry) {
                if (l1_next != nullptr) {
                    l1->next->val += carry;
                } else {
                    l1_next = new ListNode(carry);
                }
            }
            nxtNode = addTwoNumbers(l1_next, l2_next);
            newNode = new ListNode(sum, nxtNode);
        }

        return newNode;
    }
};

int main() {
    Solution S;

    ListNode a2(2);
    ListNode a1(9, &a2);
    ListNode a0(9, &a1);

    ListNode b1(9);
    ListNode b0(9, &b1);

    // 299 + 99 = 398
    ListNode* result = S.addTwoNumbers(&b0, &a0);
    ListNode* temp   = nullptr;

    // Print the result
    while (result != nullptr) {
        cout << result->val;
        temp   = result;
        result = result->next;
        delete temp;  // Deallocate memory for each node
    }
    cout << endl;

    return 0;
}
