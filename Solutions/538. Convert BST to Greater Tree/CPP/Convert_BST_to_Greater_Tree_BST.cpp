#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int currentSum = 0;

public:
    TreeNode* convertBST(TreeNode* root) {
        if (root != nullptr) {
            root->right = convertBST(root->right);
            currentSum = currentSum + root->val;
            root->val = currentSum;
            root->left = convertBST(root->left);
        }

        return root;
    }
};

void DFS_inorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    DFS_inorder(root->left);
    cout << root->val << ' ';
    DFS_inorder(root->right);
}

int main() {
    Solution* S = new Solution();

    // input tree structure:
    //
    //     rt(2)
    //     |     \
    //    n1(1)  n2(4)
    //     |      |     \
    //    n3(0)  n4(3)  n5(5)
    //
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n4 = new TreeNode(3);
    TreeNode* n3 = new TreeNode(0);
    TreeNode* n2 = new TreeNode(4, n4, n5);
    TreeNode* n1 = new TreeNode(1, n3, nullptr);
    TreeNode* rt = new TreeNode(2, n1, n2);

    TreeNode* result = S->convertBST(rt);

    DFS_inorder(result);
    cout << endl;

    return 0;
}
