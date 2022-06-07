#include <iostream>
#include <vector>

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
    void concatenate(vector<int> &target, vector<int> source){
        for(int i = 0; i < source.size(); i++){
            target.push_back(source[i]);
        }
    }

    vector<int> inorderTraversal(TreeNode* root){
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
    Solution* S = new Solution();

    TreeNode* node0 = new TreeNode(0);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node5 = new TreeNode(5);
    
    TreeNode* node1 = new TreeNode(1, node0, nullptr);
    TreeNode* node4 = new TreeNode(4, node3, node5);

    TreeNode* root  = new TreeNode(2, node1, node4);

    cout << "inorder  : ";
    vector<int> result = S->inorderTraversal(root);
    for(auto i : result){
        cout << i << ' ';
    }

    return 0;
}