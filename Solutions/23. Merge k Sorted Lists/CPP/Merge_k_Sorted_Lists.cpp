#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *next) : val(x), next(next){}
};

struct cmp{
    bool operator()(pair<ListNode*, int> &a, pair<ListNode*, int> &b){
        return a.first->val > b.first->val;
    }
};

class Solution{
public:
    ListNode* mergeKLists(vector<ListNode*> &lists){
        int lists_size = lists.size();

        //init
        priority_queue <pair<ListNode*, int>, vector<pair<ListNode*, int>>, cmp> PQ;
        for(int i = 0; i < lists_size; i++){
            if(lists[i] != nullptr){
                PQ.push(pair<ListNode*, int>(lists[i], i));
            }
        }

        ListNode *HEAD    = new ListNode();
        ListNode *pointer = HEAD;
        while(!PQ.empty()){
            pair<ListNode*, int> P = PQ.top();
            PQ.pop();

            if(P.first->next != nullptr){
                PQ.push(pair<ListNode*, int>(P.first->next, P.second));
            }
            
            pointer->next = P.first;
            pointer = pointer->next;
        }
        
        return HEAD->next;
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    ListNode *a2 = new ListNode(7);
    ListNode *a1 = new ListNode(3, a2);
    ListNode *a0 = new ListNode(1, a1);
    ListNode *b1 = new ListNode(7);
    ListNode *b0 = new ListNode(6, b1);
    vector<ListNode*> lists{a0, b0, nullptr};

    ListNode *result = S->mergeKLists(lists);
    while(result != nullptr){
        cout << result->val << ' ';
        result = result->next;
    }
    cout << endl;

    return 0;
}