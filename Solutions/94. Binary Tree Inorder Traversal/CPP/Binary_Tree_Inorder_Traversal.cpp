#include <iostream>
#include <vector>

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
    void concatenate(vector<int> &target, vector<int> source){
        for(int i = 0; i < source.size(); i++){
            target.push_back(source[i]);
        }
    }

    vector<int> inorderTraversal(TreeNode *root){
        vector<int> inorder;
        if(root == nullptr){
            return inorder;
        }
        concatenate(inorder, inorderTraversal(root->left));
        concatenate(inorder, vector<int>{root->val});
        concatenate(inorder, inorderTraversal(root->right));
        return inorder;
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    TreeNode *n0 = new TreeNode(0);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n1 = new TreeNode(1, n0, nullptr);
    TreeNode *n4 = new TreeNode(4, n3, n5);
    TreeNode *rt = new TreeNode(2, n1, n4);

    vector<int> result = S->inorderTraversal(rt);

    cout << "inorder  : ";
    for(auto i : result){
        cout << i << ' ';
    }

    return 0;
}