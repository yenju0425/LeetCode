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
    ListNode* removeNthFromEnd(ListNode *head, int n){
        int counter = 0;

        //count size of the lisked-list
        ListNode *temp = head;
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
    Solution S;
    
    //inputs
    int n = 2;
    ListNode a2(2);
    ListNode a1(7, &a2);
    ListNode hd(9, &a1);

    ListNode *result = S.removeNthFromEnd(&hd, n);
    while(result != nullptr){
        cout << result->val << ' ';
        result = result->next;
    }
    cout << endl;

    return 0;
}
