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

    vector<int> preorderTraversal(TreeNode* root){
        vector<int> preorder;
        if(root == nullptr){
            return preorder;
        }
        concatenate(preorder, vector<int>{root->val});
        concatenate(preorder, preorderTraversal(root->left));
        concatenate(preorder, preorderTraversal(root->right));
        return preorder;
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

    cout << "preorder  : ";
    vector<int> ans = S->preorderTraversal(root);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}