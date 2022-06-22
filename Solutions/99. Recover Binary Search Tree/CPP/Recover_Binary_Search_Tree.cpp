#include <iostream>
#include <algorithm>

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
    TreeNode *prev_Node  = nullptr;
    TreeNode *errorNode1 = nullptr;
    TreeNode *errorNode2 = nullptr;

public:
    void DFS_recover(TreeNode *root){ //mark the error nodes
        if(root == nullptr){
            return;
        }

        //DFS: Inorder
        DFS_recover(root->left);
        if(prev_Node != nullptr and root->val < prev_Node->val){
            if(errorNode1 == nullptr){
                errorNode1 = prev_Node;
                errorNode2 = root;
            }
            else if(errorNode1 != nullptr){
                errorNode2 = root;
                return;
            }
        }
        prev_Node = root;
        DFS_recover(root->right);
    }

    void recoverTree(TreeNode *root){
        DFS_recover(root);
        swap(errorNode1->val, errorNode2->val);
    }
};

void DFS_inorder(TreeNode *root){
    if(root == nullptr){
        return;
    }
    DFS_inorder(root->left);
    cout << root->val << ' ';
    DFS_inorder(root->right);
}

int main(){
    Solution *S = new  Solution();

    //input tree structure:
    //
    //    rt(2)
    //    |     \
    //   *n1(4) *n2(1)
    //    |      |     \
    //    n3(0)  n4(3)  n5(5)
    //
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n4 = new TreeNode(3);
    TreeNode *n3 = new TreeNode(0);
    TreeNode *n2 = new TreeNode(1, n4, n5);
    TreeNode *n1 = new TreeNode(4, n3, nullptr);
    TreeNode *rt = new TreeNode(2, n1, n2);
    
    S->recoverTree(rt);

    DFS_inorder(rt);
    cout << endl;

    return 0;
}