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
    int low  = 1;
    int high = 4;

    //input tree structure:
    //
    //    rt(2)
    //    |     \
    //    n1(1)  n2(4)
    //    |      |     \
    //    n3(0)  n4(3)  n5(5)
    //
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n4 = new TreeNode(3);
    TreeNode *n3 = new TreeNode(0);
    TreeNode *n2 = new TreeNode(4, n4, n5);
    TreeNode *n1 = new TreeNode(1, n3, nullptr);
    TreeNode *rt = new TreeNode(2, n1, n2);

    TreeNode *result = S->trimBST(rt, low, high);

    DFS_inorder(result);
    cout << endl;

    return 0;
}