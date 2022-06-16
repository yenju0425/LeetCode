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
public:
    TreeNode* trimBST(TreeNode *root, int low, int high){
        if(root == nullptr){
            return root;
        }
        if(low < root->val and high < root->val){
            return trimBST(root->left, low, high);
        }
        else if(low > root->val and high > root->val){
            return trimBST(root->right, low, high);
        }
        else{ //low <= root->val and high >= root->val
            root -> left  = trimBST(root->left,  low, high);
            root -> right = trimBST(root->right, low, high);
            return root;
        }
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
    int low  = 0;
    int high = 1;
    TreeNode *l    = new TreeNode(0);
    TreeNode *r    = new TreeNode(2);
    TreeNode *root = new TreeNode(1, l, r);

    TreeNode *node = S -> trimBST(root, low, high);

    DFS_inorder(node);
    cout << endl;

    return 0;
}