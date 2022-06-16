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
    int currentSum = 0;
    
public:
    TreeNode* convertBST(TreeNode *root){
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
    cout << root -> val << ' ';
    DFS_inorder(root -> right);
}

int main(){
    Solution *S = new Solution();

    //inputs
    TreeNode *left  = new TreeNode(0);
    TreeNode *right = new TreeNode(2);
    TreeNode *root  = new TreeNode(1, left, right);

    TreeNode *node = S -> convertBST(root);

    DFS_inorder(root);
    cout << endl;

    return 0;
}