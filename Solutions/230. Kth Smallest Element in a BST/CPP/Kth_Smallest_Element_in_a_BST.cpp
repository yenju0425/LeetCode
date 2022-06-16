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
    int counter = 0;
    int num = 0;

public:
    int kthSmallest(TreeNode *root, int k){
        counter = k;
        DFS_inorder(root);
        return num;
    }
    void DFS_inorder(TreeNode *root){
        if(root == nullptr){
            return;
        }
        DFS_inorder(root -> left);
        counter = counter - 1;
        if(counter == 0){
            num = root -> val;
            return;
        }
        DFS_inorder(root -> right);
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    TreeNode *l    = new TreeNode(0);
    TreeNode *r    = new TreeNode(2);
    TreeNode *root = new TreeNode(1, l, r);

    int node = S -> kthSmallest(root, 2);

    cout << node << endl;;

    return 0;
}