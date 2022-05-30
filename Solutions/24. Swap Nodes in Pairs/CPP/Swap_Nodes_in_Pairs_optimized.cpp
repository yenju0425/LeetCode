#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

class Solution{
public:
    ListNode* swapPairs(ListNode* head){
        ListNode* dummyHead = new ListNode(0, head);
        
        ListNode* ptr = dummyHead;

        //draw some pictures and you will find out :)
        while(ptr->next != nullptr and ptr->next->next != nullptr){
            ListNode* tmp = ptr->next;

            ptr->next = tmp->next;
            tmp->next = tmp->next->next;
            ptr->next->next = tmp;

            ptr = tmp;
        }

        return dummyHead->next;
    }
};

int main(){
    ListNode* a4 = new ListNode(4);
    ListNode* a3 = new ListNode(3, a4);
    ListNode* a2 = new ListNode(2, a3);
    ListNode* a1 = new ListNode(1, a2);

    Solution* S = new Solution();

    ListNode* A = S->swapPairs(a1);
    while(A != nullptr){
        cout << A->val;
        A = A->next;
    }
    cout << endl;

    return 0;
}