#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL){}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL){}
    Node(int _val, Node *_left, Node *_right) : val(_val), left(_left), right(_right), next(NULL){}
    Node(int _val, Node *_left, Node *_right, Node *_next) : val(_val), left(_left), right(_right), next(_next){}
};

class Solution{
public:
    Node* connect(Node *root){
        vector<queue<Node*>> Q(2); //two queues are neeeded
        int idx = 0;
        if(root != nullptr){
            Q[idx].push(root);
        }
        while(!Q[idx].empty()){
            Node *nextNode = nullptr;
            while(!Q[idx].empty()){
                Node *node = Q[idx].front();
                Q[idx].pop();
                node->next = nextNode;
                nextNode = node;
                if(node->right != nullptr){
                    Q[!idx].push(node->right);
                }
                if(node->left  != nullptr){
                    Q[!idx].push(node->left);
                }
            }
            idx = !idx; //switch to another Q
        }
        return root;
    }
};

int main(){
    Solution *S = new Solution();

    //input tree structure:
    //
    //    rt(0)
    //    |     \
    //    n1(1)  n2(2)
    //    |      |     \
    //    n3(3)  n4(4)  n5(5)
    //
    Node *n5 = new Node(5);
    Node *n4 = new Node(4);
    Node *n3 = new Node(3);
    Node *n2 = new Node(2, n4, n5);
    Node *n1 = new Node(1, n3, nullptr);
    Node *rt = new Node(0, n1, n2);

    Node *result = S->connect(rt);

    while(result != nullptr){
        Node *ptr = result;
        while(ptr != nullptr){
            cout << ptr->val << ' ';
            ptr = ptr->next;
        }
        cout << "#" << endl;

        if(result->left != nullptr){
            result = result->left;
        }
        else{
            result = result->right;
        }
    }

    return 0;
}