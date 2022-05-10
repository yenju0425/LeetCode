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
public:
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        else{
            int rightSum = sumTree(root->right);
            root->right = convertBST(root->right);

            root->val = root->val + rightSum;

            TreeNode *leftMax;
            if(root->left != nullptr){
                leftMax = root->left;
                while(leftMax->right != nullptr){
                    leftMax = leftMax->right;
                }
                leftMax->val = leftMax->val + root->val; //current root->val contains the original root->val and rightSum
            }
            root->left = convertBST(root->left);

            return root;
        }
    }
    int sumTree(TreeNode *root){
        if(root == nullptr){
            return 0;
        }
        else{
            return sumTree(root->left) + root->val + sumTree(root->right);
        }
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

    TreeNode *node = S -> convertBST(root);

    DFS_inorder(node);
    cout << endl;

    return 0;
}