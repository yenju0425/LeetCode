#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

class Solution{
public:
    ListNode* deleteDuplicates(ListNode *head){
        ListNode *cur_ptr = head;
        ListNode *nxt_ptr;
        while(cur_ptr != nullptr){
            nxt_ptr = cur_ptr->next;
            while(nxt_ptr != nullptr and nxt_ptr->val == cur_ptr->val){
                ListNode *del_ptr = nxt_ptr;
                nxt_ptr = nxt_ptr->next;
                delete del_ptr;
            }
            cur_ptr->next = nxt_ptr;
            cur_ptr       = nxt_ptr;
        }

        return head;
    }
};

int main(){
    Solution *S = new Solution();
    
    //inputs
    ListNode *a2 = new ListNode(2);
    ListNode *a1 = new ListNode(1, a2);
    ListNode *hd = new ListNode(1, a1);

    ListNode *result = S->deleteDuplicates(hd);
    while(result != nullptr){
        cout << result->val << ' ';
        result = result->next;
    }
    cout << endl;

    return 0;
}