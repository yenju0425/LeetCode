#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

/*
ex: k = 2
               NEXT_PTR
               |
          PTR  |    LAST_PTR
          |    |    |
O--> O--> O--> O--> O--> O--> O--> O--> X
|    [       ] [ Group ] [       ]
|                  |
dummyHead          |
                   currently reversing Group
*/

class Solution{
public:
    ListNode *reverseKGroup(ListNode *head, int k){
        ListNode *dummyHead = new ListNode(0, head);
        
        //init PTR
        ListNode *PTR = dummyHead;
        while(true){
            //init NEXT_PTR
            ListNode *NEXT_PTR = PTR->next;

            //init LAST_PTR
            ListNode *LAST_PTR = PTR;
            for(int i = 0; i < k; i++){
                LAST_PTR = LAST_PTR->next;
                if(LAST_PTR == nullptr){
                    return dummyHead->next;
                }
            }
    
            //init new_nxt, current, next
            ListNode *new_nxt = nullptr;
            ListNode *current = LAST_PTR->next;
            ListNode *next    = NEXT_PTR;

            while(current != LAST_PTR){
                //update new_nxt, current, next
                new_nxt = current;
                current = next;
                next    = next->next;

                //reverse
                current->next = new_nxt;
            }

            //update PTR
            PTR->next = LAST_PTR;
            PTR = NEXT_PTR;
        }
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    int k = 3;
    ListNode *a5 = new ListNode(5);
    ListNode *a4 = new ListNode(4, a5);
    ListNode *a3 = new ListNode(3, a4);
    ListNode *a2 = new ListNode(2, a3);
    ListNode *hd = new ListNode(1, a2);

    ListNode *result = S->reverseKGroup(hd, k);
    while(result != nullptr){
        cout << result->val;
        result = result->next;
    }
    cout << endl;

    return 0;
}