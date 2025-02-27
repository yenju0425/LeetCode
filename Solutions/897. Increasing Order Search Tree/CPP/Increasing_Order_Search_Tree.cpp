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
    TreeNode* newRoot     = new TreeNode();
    TreeNode* currentNode = newRoot;

public:
    TreeNode* increasingBST(TreeNode* root) {
        DFS_inorder(root);
        return newRoot->right;
    }

    void DFS_inorder(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        DFS_inorder(root->left);
        currentNode->right = new TreeNode(root->val);  // create a new node and appent it to the end
        currentNode        = currentNode->right;       // update the end node

        DFS_inorder(root->right);
    }
};

int main() {
    Solution S;

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

    TreeNode* result = S.increasingBST(rt);

    while (result != nullptr) {
        cout << result->val << ' ';
        result = result->right;
    }

    return 0;
}
