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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0, head);

        ListNode* n0 = dummyHead;
        while (n0->next != nullptr && n0->next->next != nullptr) {
            ListNode* n1 = n0->next;
            ListNode* n2 = n0->next->next;
            ListNode* n3 = n0->next->next->next;

            n1->next = n3;
            n2->next = n1;
            n0->next = n2;

            n0 = n0->next->next;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead;

        return result;
    }
};

int main() {
    Solution S;

    ListNode a4(4);
    ListNode a3(3, &a4);
    ListNode a2(2, &a3);
    ListNode hd(1, &a2);

    ListNode* result = S.swapPairs(&hd);
    while (result != nullptr) {
        cout << result->val;
        result = result->next;
    }
    cout << endl;

    return 0;
}
