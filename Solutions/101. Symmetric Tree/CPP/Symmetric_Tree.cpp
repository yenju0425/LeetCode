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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr || q == nullptr) {
            return false;
        } else if (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) {
            return true;
        }

        return false;
    }

    bool isSymmetric(TreeNode* root) { return isSameTree(root->left, root->right); }
};

int main() {
    Solution S;

    // input tree structure:
    //
    //    rt(0)
    //     |    \
    //    n1(0)  n2(0)
    //     |      |    \
    //    n3(0)  n4(0)  n5(0)

    TreeNode n5(0);
    TreeNode n4(0);
    TreeNode n3(0);
    TreeNode n2(0, &n4, &n5);
    TreeNode n1(0, &n3, nullptr);
    TreeNode rt(0, &n1, &n2);

    cout << S.isSymmetric(&rt) << endl;

    return 0;
}
