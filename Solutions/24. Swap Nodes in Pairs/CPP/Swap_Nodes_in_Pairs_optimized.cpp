#include <iostream>
#include <utility>
#include <vector>
#include <queue>

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
        
        ListNode* n0 = dummyHead;

        //draw some pictures and you will find out :)
        while(n0->next != nullptr and n0->next->next != nullptr){
            ListNode* temp = n0->next;

            n0->next = temp->next;
            temp->next = temp->next->next;
            n0->next->next = temp;

            n0 = temp;
        }

        return dummyHead->next;
    }
};

int main(){
    ListNode* a3 = new ListNode(4);
    ListNode* a2 = new ListNode(3, a3);
    ListNode* a1 = new ListNode(2, a2);
    ListNode* a0 = new ListNode(1, a1);

    Solution* S = new Solution();

    ListNode* A = S->swapPairs(a0);
    while(A != nullptr){
        cout << A->val;
        A = A->next;
    }
    cout << endl;

    return 0;
}