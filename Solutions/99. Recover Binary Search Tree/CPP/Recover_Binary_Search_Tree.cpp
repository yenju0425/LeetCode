#include <iostream>
#include <algorithm>

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
private:
    TreeNode* prevoiusNode = nullptr;
    TreeNode* errorNode1   = nullptr;
    TreeNode* errorNode2   = nullptr;

public:
    void recoverTree(TreeNode* root){
        DFS_recover(root);
        if(errorNode1 != nullptr and errorNode2 != nullptr){
            int temp        = errorNode1->val;
            errorNode1->val = errorNode2->val;
            errorNode2->val = temp;
        }
    }
    void DFS_recover(TreeNode* root){
        if(root == nullptr){
            return;
        }
        DFS_recover(root->left);
        if(prevoiusNode != nullptr and errorNode1 == nullptr){
            if(root->val < prevoiusNode->val){ //if current root node < previous node: first error node is found!
                errorNode1 = prevoiusNode;
                errorNode2 = root;
            }
        }
        else if(errorNode1 != nullptr){
            if(root->val < errorNode1->val){
                errorNode2 = root;
            }
        }
        prevoiusNode = root;
        DFS_recover(root->right);
    }
};

void DFS_inorder(TreeNode* root){
    if(root == nullptr){
        return;
    }
    DFS_inorder(root->left);
    cout << root->val << ' ';
    DFS_inorder(root->right);
}

int main(){
    Solution* S = new  Solution();

    TreeNode* node2 = new TreeNode(2);
    TreeNode* node4 = new TreeNode(4, node2,   nullptr);
    TreeNode* node1 = new TreeNode(1, nullptr, nullptr);
    TreeNode* root  = new TreeNode(3, node1,   node4);
    
    S->recoverTree(root);

    DFS_inorder(root);
    cout << endl;

    return 0;
}