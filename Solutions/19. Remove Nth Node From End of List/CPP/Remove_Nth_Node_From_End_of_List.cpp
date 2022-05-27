#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int counter = 0;

        //count size of the lisked-list
        ListNode* temp = head;
        while(temp != nullptr){
            counter = counter + 1; 
            temp = temp->next;
        }

        if(counter == n){
            return head->next;
        }

        //remove
        temp = new ListNode(0, head);
        for(int i = 0; i < counter - n; i++){
            temp = temp->next;
        }
        temp->next = temp->next->next;

        return head;
    }
};

int main(){
    ListNode* a2 = new ListNode(2);
    ListNode* a1 = new ListNode(7, a2);
    ListNode* a0 = new ListNode(9, a1);

    Solution* S = new Solution();
    ListNode* A = S->removeNthFromEnd(a0, 2);

    while(A != nullptr){
        cout << A->val << " ";
        A = A->next;
    }
    cout << endl;

    return 0;
}