#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0, head);
        
        ListNode* ptr = dummyHead;

        //draw some pictures and you will find out :)
        while(ptr->next != nullptr && ptr->next->next != nullptr) {
            ListNode* tmp = ptr->next;

            ptr->next = tmp->next;
            tmp->next = tmp->next->next;
            ptr->next->next = tmp;

            ptr = tmp;
        }

        ListNode* result = dummyHead->next;
        delete dummyHead;

        return result;
    }
};

int main() {
    Solution S;
    
    //inputs
    ListNode a4(4);
    ListNode a3(3, &a4);
    ListNode a2(2, &a3);
    ListNode hd(1, &a2);

    ListNode* result = S.swapPairs(&hd);
    while(result != nullptr) {
        cout << result->val;
        result = result->next;
    }
    cout << endl;

    return 0;
}
