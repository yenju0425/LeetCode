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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyHead_geq = new ListNode(0);  //>=
        ListNode* dummyHead_ltn = new ListNode(0);  //<

        ListNode* geq_ptr = dummyHead_geq;
        ListNode* ltn_ptr = dummyHead_ltn;

        while (head != nullptr) {
            if (head->val >= x) {
                geq_ptr->next = head;
                geq_ptr       = head;
            } else {
                ltn_ptr->next = head;
                ltn_ptr       = head;
            }

            head = head->next;
        }

        ltn_ptr->next = dummyHead_geq->next;
        geq_ptr->next = nullptr;

        ListNode* result = dummyHead_ltn->next;
        delete dummyHead_ltn;
        delete dummyHead_geq;

        return result;
    }
};

int main() {
    Solution S;

    int x = 3;
    ListNode n2(2);
    ListNode n1(3, &n2);
    ListNode hd(9, &n1);

    ListNode* result = S.partition(&hd, x);

    while (result != nullptr) {
        cout << result->val;
        result = result->next;
    }
    cout << endl;

    return 0;
}
