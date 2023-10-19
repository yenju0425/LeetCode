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
        if (p == nullptr and q == nullptr) {
            return true;
        }
        if (p == nullptr xor q == nullptr) {
            return false;
        }
        if (p->val == q->val and isSameTree(p->left, q->left) and isSameTree(p->right, q->right)) {
            return true;
        }
        return false;
    }
};

int main() {
    Solution* S = new Solution();

    // inputs
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n4 = new TreeNode(4, n2, nullptr);
    TreeNode* n1 = new TreeNode(1, nullptr, nullptr);

    TreeNode* r1 = new TreeNode(3, n4, n1);
    TreeNode* r2 = new TreeNode(3, n1, n4);

    cout << S->isSameTree(r1, r2) << endl;

    return 0;
}
