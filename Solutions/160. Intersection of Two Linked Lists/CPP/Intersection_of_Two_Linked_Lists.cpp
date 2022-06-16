#include <iostream>
#include <vector>

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
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB){
        ListNode *Intersection;

        ListNode *ptr;
        for(ListNode *ptr = headA; ptr != nullptr; ptr = ptr->next){
            ptr->val = (-1)  *ptr->val;
        }
        for(ListNode *ptr = headB; ptr != nullptr; ptr = ptr->next){
            if(ptr->val < 0){
                Intersection = ptr;
                break;
            }
        }

        //restore listA
        for(ListNode *ptr = headA; ptr != nullptr; ptr = ptr->next){
            ptr->val = (-1)  *ptr->val;
        }

        return Intersection;
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    ListNode *c2 = new ListNode(5);
    ListNode *c1 = new ListNode(4, c2);
    ListNode *c0 = new ListNode(8, c1);

    ListNode *a1 = new ListNode(1, c0);
    ListNode *a0 = new ListNode(4, a1);
    
    ListNode *b2 = new ListNode(1, c0);
    ListNode *b1 = new ListNode(6, b2);
    ListNode *b0 = new ListNode(5, b1);

    cout << S->getIntersectionNode(a0, b0)->val << endl;

    return 0;
}