#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
private:
    queue<TreeNode*> Tree;

public:
    BSTIterator(TreeNode* root) {
        //Practice: using stack to store value (in-order, how about pre-order and post-order)
        TreeNode* currentNode = root;
        stack<TreeNode*> S;
        while(currentNode != nullptr || !S.empty()){
            if(currentNode != nullptr){
                S.push(currentNode);
                currentNode = currentNode->left;
            }
            else{
                currentNode = S.top();
                S.pop();
                Tree.push(currentNode);
                currentNode = currentNode->right;
            }
        }
    }
    
    int next() {
        if(Tree.empty()){
            return -1;
        }
        else{
            TreeNode* n = Tree.front();
            Tree.pop();
            return n->val;
        }
    }
    
    bool hasNext() {
        return !Tree.empty();
    }
};

int main(){
    TreeNode* node0 = new TreeNode(0);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node5 = new TreeNode(5);
    
    TreeNode* node1 = new TreeNode(1, node0, nullptr);
    TreeNode* node4 = new TreeNode(4, node3, node5);

    TreeNode* root  = new TreeNode(2, node1, node4);

    BSTIterator* B = new BSTIterator(root);

    cout << B->next() << endl;    // return 3
    cout << B->next() << endl;    // return 7
    cout << B->next() << endl;    // return 9
    cout << B->next() << endl;    // return 15
    cout << B->next() << endl;    // return 20
    cout << B->next() << endl;    // return 3
    cout << B->next() << endl;    // return 7
    cout << B->next() << endl;    // return 9
    cout << B->next() << endl;    // return 15
    cout << B->next() << endl;    // return 20
    return 0;
}