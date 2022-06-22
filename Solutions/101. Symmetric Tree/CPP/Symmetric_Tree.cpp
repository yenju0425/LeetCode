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
    bool isSameTree(TreeNode *p, TreeNode *q){
        if(p == nullptr and q == nullptr){
            return true;
        }
        if(p == nullptr xor q == nullptr){
            return false;
        }
        if(p->val == q->val and isSameTree(p->left, q->right) and isSameTree(p->right, q->left)){
            return true;
        }
        return false;
    }

    bool isSymmetric(TreeNode *root){
        return isSameTree(root->left, root->right);
    }
};

int main(){
    Solution *S = new  Solution();

    //input tree structure:
    //
    //    rt(0)
    //    |     \
    //    n1(0)  n2(0)
    //    |      |     \
    //    n3(0)  n4(0)  n5(0)
    //
    TreeNode *n5 = new TreeNode(0);
    TreeNode *n4 = new TreeNode(0);
    TreeNode *n3 = new TreeNode(0);
    TreeNode *n2 = new TreeNode(0, n4, n5);
    TreeNode *n1 = new TreeNode(0, n3, nullptr);
    TreeNode *rt = new TreeNode(0, n1, n2);
    
    cout << S->isSymmetric(rt) << endl;

    return 0;
}