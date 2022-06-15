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
    ListNode* mergeTwoLists(ListNode *list1, ListNode *list2){
        ListNode *headNode    = new ListNode(0, list1);
        ListNode *currentNode = headNode;

        //insert list2 to list1
        while(list1 != nullptr or list2 != nullptr){
            if(list1 == nullptr or (list2 != nullptr and list2->val < list1->val)){ //list2 is smaller (insert list2)
                currentNode->next = list2;
                currentNode = list2;
                list2 = list2->next;
            }
            else{
                currentNode->next = list1;
                currentNode = list1;
                list1 = list1->next;
            }
        }

        return headNode->next;
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    ListNode *n2 = new ListNode(4);
    ListNode *n1 = new ListNode(2, n2);
    ListNode *n0 = new ListNode(1, n1);
    ListNode *m2 = new ListNode(4);
    ListNode *m1 = new ListNode(3, m2);
    ListNode *m0 = new ListNode(1, m1);

    ListNode *result = S->mergeTwoLists(n0, m0);

    while(result != nullptr){
        cout << result->val << endl;
        result = result->next;  
    }

    return 0;
}