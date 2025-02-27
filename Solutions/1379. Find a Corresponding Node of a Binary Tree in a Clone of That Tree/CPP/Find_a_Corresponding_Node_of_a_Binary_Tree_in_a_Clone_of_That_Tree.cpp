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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (original == nullptr) {
            return nullptr;
        } else if (original == target) {
            return cloned;
        }

        TreeNode* findLeft = getTargetCopy(original->left, cloned->left, target);
        if (findLeft != nullptr) {
            return findLeft;
        }
        TreeNode* findRight = getTargetCopy(original->right, cloned->right, target);
        if (findRight != nullptr) {
            return findRight;
        }

        return nullptr;
    }
};

int main() {
    Solution S;

    // original tree structure:
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

    // cloned
    TreeNode* _n5 = new TreeNode(5);
    TreeNode* _n4 = new TreeNode(3);
    TreeNode* _n3 = new TreeNode(0);
    TreeNode* _n2 = new TreeNode(4, _n4, _n5);
    TreeNode* _n1 = new TreeNode(1, _n3, nullptr);
    TreeNode* _rt = new TreeNode(2, _n1, _n2);

    cout << S.getTargetCopy(rt, _rt, n4) << endl;
    cout << "Real Target: " << _n4 << endl;

    return 0;
}
