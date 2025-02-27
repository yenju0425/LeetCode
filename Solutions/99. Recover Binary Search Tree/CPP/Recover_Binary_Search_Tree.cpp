#include <algorithm>
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
    TreeNode* prev_Node  = nullptr;
    TreeNode* errorNode1 = nullptr;
    TreeNode* errorNode2 = nullptr;

public:
    void inorderRecover(TreeNode* root) {  // mark the error nodes
        if (root == nullptr) {
            return;
        }

        inorderRecover(root->left);
        if (prev_Node != nullptr && root->val < prev_Node->val) {
            if (errorNode1 == nullptr) {
                errorNode1 = prev_Node;
                errorNode2 = root;
            } else if (errorNode1 != nullptr) {
                errorNode2 = root;
                return;
            }
        }
        prev_Node = root;
        inorderRecover(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorderRecover(root);
        swap(errorNode1->val, errorNode2->val);
    }

    void postorderPrint(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        postorderPrint(root->left);
        postorderPrint(root->right);

        cout << root->val << " ";
    }
};

int main() {
    Solution S;

    // input tree structure:
    //
    //    rt(2)
    //     |    \
    //   *n1(4) *n2(1)
    //     |      |    \
    //    n3(0)  n4(3)  n5(5)

    TreeNode n5(5);
    TreeNode n4(3);
    TreeNode n3(0);
    TreeNode n2(1, &n4, &n5);
    TreeNode n1(4, &n3, nullptr);
    TreeNode rt(2, &n1, &n2);

    S.recoverTree(&rt);

    S.postorderPrint(&rt);
    cout << endl;

    return 0;
}
