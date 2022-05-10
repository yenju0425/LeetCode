#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int currentSum = 0; //it's better to initialize by yourself
    
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root != nullptr){
            root->right = convertBST(root->right);
            currentSum  = currentSum + root->val;
            root->val   = currentSum;
            root->left  = convertBST(root->left);
        }
        return root;
    }
};

void DFS_inorder(TreeNode *root){
    if(root == nullptr){
        return;
    }
    DFS_inorder(root -> left);
    cout << root -> val << " ";
    DFS_inorder(root -> right);
}

int main(){
    TreeNode *l    = new TreeNode(0);
    TreeNode *r    = new TreeNode(2);
    TreeNode *root = new TreeNode(1, l, r);

    Solution *S = new Solution();

    //TreeNode *node = S -> convertBST(root);

    DFS_inorder(root);
    cout << endl;

    return 0;
}