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
        }
        else if (p == nullptr || q == nullptr) {
            return false;
        }
        else if (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) {
            return true;
        }

        return false;
    }
};

int main() {
    Solution S;

    // inputs
    TreeNode n2(2);
    TreeNode n4(4, &n2, nullptr);
    TreeNode n1(1, nullptr, nullptr);

    TreeNode r1(3, &n4, &n1);
    TreeNode r2(3, &n1, &n4);

    cout << S.isSameTree(&r1, &r2) << endl;

    return 0;
}
