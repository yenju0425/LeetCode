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
    bool hasCycle(ListNode *head){
        ListNode *dummyHead = new ListNode(0, head);

        ListNode *pre_ptr = dummyHead;
        ListNode *cur_ptr = head;
        while(cur_ptr != dummyHead and cur_ptr != nullptr){
            ListNode *nxt_ptr = cur_ptr->next;
            cur_ptr->next = pre_ptr;

            pre_ptr = cur_ptr;
            cur_ptr = nxt_ptr;
        }

        //if cur_ptr go back to dummyHead, there must exist a loop :)
        return (cur_ptr == dummyHead) ? true : false;
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    ListNode *n2 = new ListNode(3);
    ListNode *n1 = new ListNode(9, n2);
    ListNode *hd = new ListNode(0, n1);

    //create cycle
    n2->next = n1;

    cout << S->hasCycle(nullptr) << endl;

    return 0;
}