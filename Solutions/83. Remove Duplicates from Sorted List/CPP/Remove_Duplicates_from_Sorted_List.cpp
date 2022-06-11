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
    ListNode* deleteDuplicates(ListNode* head){
        ListNode* pointer = head;
        while(pointer != nullptr){
            ListNode* pointer_next = pointer->next;
            while(pointer_next != nullptr and pointer_next->val == pointer->val){
                pointer_next = pointer_next->next;
            }
            pointer->next = pointer_next;
            pointer       = pointer_next;
        }

        return head;
    }
};

int main(){
    Solution* S = new Solution();
    
    //inputs
    ListNode* a2 = new ListNode(2);
    ListNode* a1 = new ListNode(1, a2);
    ListNode* hd = new ListNode(1, a1);

    ListNode* result = S->deleteDuplicates(hd);
    while(result != nullptr){
        cout << result->val << ' ';
        result = result->next;
    }
    cout << endl;

    return 0;
}