#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*
ex: k = 2

          CUR_PTR   LST_PTR
          |         |
O--> O--> O--> O--> O--> O--> O--> O--> X
|    [       ] [ Group ] [       ]
|                  |
dummyHead          currently reversing Group

*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyHead = new ListNode(0, head);

        // init CUR_PTR
        ListNode* CUR_PTR = dummyHead;
        while (true) {
            // init LAST_PTR
            ListNode* LST_PTR = CUR_PTR;
            for (int i = 0; i < k; ++i) {
                LST_PTR = LST_PTR->next;
                if (LST_PTR == nullptr) {
                    return dummyHead->next;
                }
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
            CUR_PTR->next = LST_PTR;
            CUR_PTR = NEW_NXT;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead;

        return result;
    }
};

int main() {
    Solution S;

    // inputs
    int k = 3;
    ListNode a5(5);
    ListNode a4(4, &a5);
    ListNode a3(3, &a4);
    ListNode a2(2, &a3);
    ListNode hd(1, &a2);

    ListNode* result = S.reverseKGroup(&hd, k);
    while (result != nullptr) {
        cout << result->val;
        result = result->next;
    }
    cout << endl;

    return 0;
}
