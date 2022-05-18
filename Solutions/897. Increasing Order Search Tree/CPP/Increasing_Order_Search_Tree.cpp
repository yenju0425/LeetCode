#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

class Solution{
private:
    TreeNode* newRoot     = new TreeNode();
    TreeNode* currentNode = newRoot;

public:
    TreeNode* increasingBST(TreeNode* root){
        DFS_inorder(root);
        return newRoot->right;
    }
    void DFS_inorder(TreeNode *root){
        if(root == nullptr){
            return;
        }
        DFS_inorder(root->left);
        currentNode->right = new TreeNode(root->val); //create a new node and appent it to the end
        currentNode = currentNode->right; //update the end node

        DFS_inorder(root->right);
    }
};

int main(){
    TreeNode *l    = new TreeNode(0);
    TreeNode *r    = new TreeNode(2);
    TreeNode *root = new TreeNode(1, l, r);

    Solution *S = new Solution();

    TreeNode *node = S->increasingBST(root);
    while(node != nullptr){
        cout << node->val;
        node = node->right;
    }
    return 0;
}