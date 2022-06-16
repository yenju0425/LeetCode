#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

class BSTIterator{
private:
    queue<TreeNode*> Tree;

public:
    BSTIterator(TreeNode *root){
        TreeNode *currentNode = root;
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
    
    int next(){
        if(Tree.empty()){
            return -1;
        }
        else{
            TreeNode *n = Tree.front();
            Tree.pop();
            return n->val;
        }
    }
    
    bool hasNext(){
        return !Tree.empty();
    }
};

int main(){
    //inputs
    TreeNode *n0 = new TreeNode(0);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n1 = new TreeNode(1, n0, nullptr);
    TreeNode *n4 = new TreeNode(4, n3, n5);
    TreeNode *rt = new TreeNode(2, n1, n4);

    BSTIterator *B = new BSTIterator(rt);

    cout << B->next() << endl;
    cout << B->next() << endl;
    cout << B->next() << endl;
    cout << B->next() << endl;
    cout << B->next() << endl;
    cout << B->next() << endl;
    cout << B->next() << endl;
    cout << B->next() << endl;

    return 0;
}