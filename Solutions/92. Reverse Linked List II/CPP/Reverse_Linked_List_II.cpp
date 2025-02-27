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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummyHead = new ListNode(0, head);

        // init CUR_PTR
        ListNode* CUR_PTR = dummyHead;
        for (int i = 1; i < left; ++i) {
            CUR_PTR = CUR_PTR->next;
        }

        // init LAST_PTR
        ListNode* LST_PTR = dummyHead;
        for (int i = 1; i <= right; ++i) {
            LST_PTR = LST_PTR->next;
        }

        // init new_nxt, current, next
        ListNode* new_nxt = nullptr;
        ListNode* cur_ptr = LST_PTR->next;
        ListNode* nxt_ptr = CUR_PTR->next;

        while (cur_ptr != LST_PTR) {
            // update new_nxt, current, next
            new_nxt = cur_ptr;
            cur_ptr = nxt_ptr;
            nxt_ptr = nxt_ptr->next;

            // reverse
            cur_ptr->next = new_nxt;
        }

        // update PTR
        ListNode* NEW_NXT = CUR_PTR->next;
        CUR_PTR->next     = LST_PTR;
        CUR_PTR           = NEW_NXT;

        ListNode* result = dummyHead->next;
        delete dummyHead;

        return result;
    }
};

int main() {
    Solution S;

    ListNode n5(5);
    ListNode n4(4, &n5);
    ListNode n3(3, &n4);
    ListNode n2(2, &n3);
    ListNode n1(1, &n2);

    ListNode* result = S.reverseBetween(&n1, 2, 3);

    while (result != nullptr) {
        cout << result->val << ' ';
        result = result->next;
    }
    cout << endl;

    return 0;
}
