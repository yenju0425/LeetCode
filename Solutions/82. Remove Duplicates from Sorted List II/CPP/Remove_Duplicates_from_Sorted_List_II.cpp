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
        ListNode *dummyHead = new ListNode(0, head);

        ListNode *cur_ptr = dummyHead;
        ListNode *nxt_ptr;
        while(cur_ptr != nullptr){
            nxt_ptr = cur_ptr->next;
            while(nxt_ptr != nullptr and nxt_ptr->next != nullptr and nxt_ptr->val == nxt_ptr->next->val){
                int num = nxt_ptr->val;
                while(nxt_ptr != nullptr and nxt_ptr->val == num){ //clean up the following node with val == num
                    ListNode *del_ptr = nxt_ptr;
                    nxt_ptr = nxt_ptr->next;
                    delete del_ptr;
                }
            }
            cur_ptr->next = nxt_ptr;
            cur_ptr       = nxt_ptr;
        }

        return dummyHead->next;
    }
};

int main(){
    Solution *S = new Solution();
    
    //inputs
    ListNode *n2 = new ListNode(2);
    ListNode *n1 = new ListNode(1, n2);
    ListNode *hd = new ListNode(1, n1);

    ListNode *result = S->deleteDuplicates(hd);
    while(result != nullptr){
        cout << result->val << ' ';
        result = result->next;
    }
    cout << endl;

    return 0;
}