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
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);
    Node *n1 = new Node(1, n3, n4);
    Node *n5 = new Node(5);
    Node *n2 = new Node(2, nullptr, n5);
    Node *rt = new Node(0, n1, n2);

    Solution* S = new Solution();

    rt = S->connect(rt);

    //using BFS traversal to check every "next" pointer
    queue<Node*> Q;
    Q.push(rt);
    while(!Q.empty()){
        Node* node = Q.front();
        Q.pop();
        cout << node->val << " ";
        if(node->next == nullptr){
            cout << "#" << endl;
        }
        else{
            cout << node->next->val << endl;
        }
        
        //push new nodes to Q
        if(node->left  != nullptr){
            Q.push(node->left);
        }
        if(node->right != nullptr){
            Q.push(node->right);
        }
    }
    return 0;
}