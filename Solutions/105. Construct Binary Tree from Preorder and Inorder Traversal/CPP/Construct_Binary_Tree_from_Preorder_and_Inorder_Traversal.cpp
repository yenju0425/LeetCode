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
private:
    int size;

    vector<int> preorder;
    vector<int> inorder;

public:
    TreeNode* treeBuilder(int p_l, int p_r, int i_l, int i_r){
        if(p_l == p_r){
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[p_l]);

        int i_idx = i_l;
        int p_idx = p_l + 1;
        while(inorder[i_idx] != preorder[p_l]){
            i_idx = i_idx + 1;
            p_idx = p_idx + 1;
        }

        node->left  = treeBuilder(p_l + 1, p_idx, i_l, i_idx);
        node->right = treeBuilder(p_idx, p_r, i_idx + 1, i_r);

        return node;
    }

    TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder){
        this->size = preorder.size();

        this->preorder = preorder;
        this->inorder  = inorder;

        return treeBuilder(0, size, 0, size);
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
    //    rt(3)
    //    |     \
    //    n1(9)  n2(0)
    //           |     \
    //           n4(5)  n5(7)
    //
    vector<int> preorder{3, 9, 0, 5, 7};
    vector<int>  inorder{9, 3, 5, 0, 7};
    
    TreeNode *result = S->buildTree(preorder, inorder);

    DFS_inorder(result);
    cout << endl;

    return 0;
}