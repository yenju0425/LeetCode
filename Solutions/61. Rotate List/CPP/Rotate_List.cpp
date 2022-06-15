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
    ListNode *rotateRight(ListNode *head, int k){
        if(head == nullptr){
            return head;
        }

        //store every ListNode to nodeList
        vector<ListNode*> nodeList;
        for(ListNode *ptr = head; ptr != nullptr; ptr = ptr->next){
            nodeList.push_back(ptr);
        }

        int nodeList_size = nodeList.size();

        //no rotation is needed if k % nodeList_size == 0
        k = k % nodeList_size;
        if(k == 0){
            return head;
        }

        //make a circular linked-list, return the new head (nodeList[head - 1]->next should be nullptr)
        nodeList.back()->next = nodeList.front();
        nodeList[nodeList_size - k - 1]->next = nullptr;
        return nodeList[nodeList_size - k];
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