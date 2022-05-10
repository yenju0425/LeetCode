#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode();
        ListNode* currentNode = head;

        while(list1 != nullptr or list2 != nullptr){
            if(list2 == nullptr or (list1 != nullptr and list1->val < list2->val)){
                currentNode->next = new ListNode(list1->val);
                list1 = list1 -> next;
            }
            else{
                currentNode->next = new ListNode(list2->val);
                list2 = list2 -> next;
            }
            currentNode = currentNode->next;
        }
        return head->next;
    }
};

int main(){
    Solution *S = new Solution;

    ListNode *n2 = new ListNode(4);
    ListNode *n1 = new ListNode(2, n2);
    ListNode *n0 = new ListNode(1, n1);

    ListNode *m2 = new ListNode(4);
    ListNode *m1 = new ListNode(3, m2);
    ListNode *m0 = new ListNode(1, m1);

    ListNode *a = S->mergeTwoLists(n0, m0);

    while(a != nullptr){
        cout << a->val << endl;
        a = a -> next;  
    }
}