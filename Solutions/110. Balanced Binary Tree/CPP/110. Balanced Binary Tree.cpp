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
    int treeHeight(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return max(treeHeight(root->left), treeHeight(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root){
        if(root == nullptr){
            return true;
        }
    
        return isBalanced(root->left) and isBalanced(root->right) and (abs(treeHeight(root->left) - treeHeight(root->right)) <= 1);
    }
};

int main(){
    Solution *S = new  Solution();

    //input tree structure:
    //
    //    rt(0)
    //    |     \
    //    n1(1)  n2(2)
    //    |      |     \
    //    n3(3)  n4(4)  n5(5)
    //
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n2 = new TreeNode(2, n4, n5);
    TreeNode *n1 = new TreeNode(1, n3, nullptr);
    TreeNode *rt = new TreeNode(0, n1, n2);
    
    cout << S->isBalanced(rt) << endl;

    return 0;
}