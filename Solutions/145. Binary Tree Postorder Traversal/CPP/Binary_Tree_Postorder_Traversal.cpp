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

    vector<int> postorderTraversal(TreeNode* root){
        vector<int> postorder;
        if(root == nullptr){
            return postorder;
        }
        concatenate(postorder, postorderTraversal(root->left));
        concatenate(postorder, postorderTraversal(root->right));
        concatenate(postorder, vector<int>{root->val});
        return postorder;
    }
};

int main(){
    Solution *S = new Solution();
    TreeNode* node0 = new TreeNode(0);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node5 = new TreeNode(5);
    
    TreeNode* node1 = new TreeNode(1, node0, nullptr);
    TreeNode* node4 = new TreeNode(4, node3, node5);

    TreeNode* root  = new TreeNode(2, node1, node4);

    cout << "postorder  : ";
    vector<int> ans = S->postorderTraversal(root);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}