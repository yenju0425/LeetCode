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
    ListNode* reverseList(ListNode *head){
        ListNode* pre_ptr = nullptr;
        ListNode* cur_ptr = head;
        while(cur_ptr != nullptr){
            ListNode* nxt_ptr = cur_ptr->next;
            cur_ptr->next = pre_ptr;

            pre_ptr = cur_ptr;
            cur_ptr = nxt_ptr;
        }

        return pre_ptr;
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    ListNode *n3 = new ListNode(3);
    ListNode *n2 = new ListNode(2, n3);
    ListNode *n1 = new ListNode(1, n2);

    ListNode *result = S->reverseList(n1);

    while(result != nullptr){
        cout << result->val << ' ';
        result = result->next;
    }
    cout << endl;

    return 0;
}