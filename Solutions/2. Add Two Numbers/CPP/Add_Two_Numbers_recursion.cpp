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
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2){
        ListNode *nextNode = nullptr;
        ListNode *newNode  = nullptr;

        if(l1 != nullptr or l2 != nullptr){
            int l1_val = 0;
            int l2_val = 0;
            ListNode *l1_next = nullptr;
            ListNode *l2_next = nullptr;

            if(l1 != nullptr){
                l1_val  = l1->val;
                l1_next = l1->next;
            }
            if(l2 != nullptr){
                l2_val  = l2->val;
                l2_next = l2->next;
            }

            int temp  = l1_val + l2_val;
            int sum   = temp % 10;
            int carry = temp / 10;

            //deal with the carry bit issue
            if(carry){
                if(l1_next != nullptr){
                    l1->next->val += carry;
                }
                else{
                    l1_next = new ListNode(carry);
                }
            }
            nextNode = addTwoNumbers(l1_next, l2_next);
            newNode  = new ListNode(sum, nextNode);
        }
        return newNode;
    }
};

int main(){
    Solution *S = new Solution();

    ListNode *a2 = new ListNode(2);
    ListNode *a1 = new ListNode(9, a2);
    ListNode *a0 = new ListNode(9, a1);

    ListNode *b1 = new ListNode(9);
    ListNode *b0 = new ListNode(9, b1);

    //299 + 99 = 398
    ListNode *result = S->addTwoNumbers(b0, a0);
    while(result != nullptr){
        cout << result->val;
        result = result->next;
    }
    cout << endl;

    return 0;
}