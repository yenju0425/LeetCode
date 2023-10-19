#include <iostream>
#include <vector>

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        if (root->left == nullptr and root->right == nullptr) {
            return (root->val == targetSum) ? true : false;
        }

        int newTargetSum = targetSum - root->val;
        bool result = false;
        if (root->left != nullptr) {
            result = result or hasPathSum(root->left, newTargetSum);
        }
        if (root->right != nullptr) {
            result = result or hasPathSum(root->right, newTargetSum);
        }

        return result;
    }
};

int main() {
    Solution* S = new Solution();

    // inputs
    int targetSum = 7;

    // input tree structure:
    //
    //     rt(0)
    //     |     \
    //    n1(1)  n2(2)
    //     |      |     \
    //    n3(3)  n4(4)  n5(5)
    //
    TreeNode* n5 = new TreeNode(5);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(2, n4, n5);
    TreeNode* n1 = new TreeNode(1, n3, nullptr);
    TreeNode* rt = new TreeNode(0, n1, n2);

    cout << S->hasPathSum(rt, targetSum) << endl;

    return 0;
}
