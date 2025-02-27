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
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int left  = minDepth(root->left);
        int right = minDepth(root->right);
        if (left == 0 xor right == 0) {
            return left + right + 1;
        }
        return min(left, right) + 1;
    }
};

int main() {
    Solution S;

    // input tree structure:
    //
    //     rt(0)
    //     |     \
    //    n1(0)  n2(0)
    //     |      |     \
    //    n3(0)  n4(0)  n5(0)
    //
    TreeNode* n5 = new TreeNode(0);
    TreeNode* n4 = new TreeNode(0);
    TreeNode* n3 = new TreeNode(0);
    TreeNode* n2 = new TreeNode(0, n4, n5);
    TreeNode* n1 = new TreeNode(0, n3, nullptr);
    TreeNode* rt = new TreeNode(0, n1, n2);

    cout << S.minDepth(rt) << endl;

    return 0;
}
