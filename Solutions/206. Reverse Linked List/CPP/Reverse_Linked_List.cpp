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
    ListNode* reverseList(ListNode *curNode){
        ListNode *preNode = nullptr;
        while(curNode != nullptr){
            ListNode *temp = preNode;
            preNode = curNode;
            curNode = curNode->next;

            //reverse
            preNode->next = temp;
        }
        return preNode;
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