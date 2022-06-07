#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};

class Solution{
public:
    TreeNode* searchBST(TreeNode* root, int val){
        if(root == nullptr){
            return root;
        }
        else{
            if(val < root -> val){
                return searchBST(root -> left, val);
            }
            else if(val > root -> val){
                return searchBST(root -> right, val);
            }
            else{
                return root;
            }
        }
    }
};

void DFS_inorder(TreeNode* root){
    if(root == nullptr){
        return;
    }
    DFS_inorder(root -> left);
    cout << root -> val << ' ';
    DFS_inorder(root -> right);
}

int main(){
    Solution* S = new Solution();

    //inputs
    int val = 0;
    TreeNode* l    = new TreeNode(0);
    TreeNode* r    = new TreeNode(2);
    TreeNode* root = new TreeNode(1, l, r);

    TreeNode* node = S -> searchBST(root, val);

    DFS_inorder(node);

    return 0;
}