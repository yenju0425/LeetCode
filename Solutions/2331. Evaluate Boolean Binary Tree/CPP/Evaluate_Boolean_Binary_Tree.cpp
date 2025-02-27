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
public:
    bool evaluateTree(TreeNode* root) {
        if (root->left == nullptr) {  // leaf node
            return root->val;
        } else {                   // none leaf node
            if (root->val == 2) {  // or
                return evaluateTree(root->left) || evaluateTree(root->right);
            } else {  // and
                return evaluateTree(root->left) && evaluateTree(root->right);
            }
        }
    }
};

int main() {
    Solution S;

    // input tree structure:
    //
    //     rt(&)
    //     |     \
    //    n1(&)  n2(|)
    //     |      |     \
    //    n3(0)  n4(0)  n5(1)
    //
    TreeNode* n5 = new TreeNode(1);
    TreeNode* n4 = new TreeNode(0);
    TreeNode* n3 = new TreeNode(0);
    TreeNode* n2 = new TreeNode(2, n4, n5);
    TreeNode* n1 = new TreeNode(3, n3, nullptr);
    TreeNode* rt = new TreeNode(3, n1, n2);

    cout << S.evaluateTree(rt) << endl;

    return 0;
}
