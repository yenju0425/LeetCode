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
    ListNode* rotateRight(ListNode *head, int k){
        if(head == nullptr){
            return head;
        }

        int numOfNodes = 0;
        ListNode *lastNode = nullptr;
        for(ListNode *ptr = head; ptr != nullptr; ptr = ptr->next){
            numOfNodes = numOfNodes + 1;
            lastNode = ptr;
        }

        k = k % numOfNodes;
        if(k == 0){
            return head;
        }

        lastNode->next = head;
        k = numOfNodes - k;
        for(int i = 0; i < k; i++){
            lastNode = head;
            head = head->next;
        }
        lastNode->next = nullptr;

        return head;
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    int k = 3;
    ListNode *n4 = new ListNode(4);
    ListNode *n3 = new ListNode(3, n4);
    ListNode *n2 = new ListNode(2, n3);
    ListNode *n1 = new ListNode(1, n2);
    ListNode *hd = new ListNode(0, n1);

    ListNode *result = S->rotateRight(hd, k);

    while(result != nullptr){
        cout << result->val << ' ';
        result = result->next;
    }
    cout << endl;

    return 0;
}