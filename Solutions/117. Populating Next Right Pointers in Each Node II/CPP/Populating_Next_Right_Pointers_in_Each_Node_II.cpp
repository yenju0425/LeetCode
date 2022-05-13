#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL){}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL){}

    //for initializing the binary search tree
    Node(int _val, Node* _left, Node* _right)
        : val(_val), left(_left), right(_right), next(NULL){}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next){}
};

class Solution{
public:
    Node* connect(Node* root){
        vector<queue<Node*>> Q(2); //two queues are neeeded
        int idx = 0;
        if(root != nullptr){
            Q[idx].push(root);
        }
        while(!Q[idx].empty()){
            int _idx = (idx + 1) % 2; //_idx: another queue's index
            Node* nextNode = nullptr;
            while(!Q[idx].empty()){
                Node* node = Q[idx].front();
                Q[idx].pop();
                node->next = nextNode;
                nextNode = node;
                if(node->right != nullptr){
                    Q[_idx].push(node->right);
                }
                if(node->left  != nullptr){
                    Q[_idx].push(node->left);
                }
            }
            idx = _idx; //switch to another Q
        }
        return root;
    }
};

int main(){
    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3, n1, n2);
    Node *n4 = new Node(4);
    Node *n5 = new Node(5, nullptr, n4);
    Node *rt = new Node(99, n3, n5);

    Solution* S = new Solution();
    
    rt = S->connect(rt);

    return 0;
}