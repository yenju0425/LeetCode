#include <iostream>
#include <queue>
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
private:
    int nums_size;
    vector<int> nums;

public:
    TreeNode* treeBuilder(int idx, int n) {
        if (n == 0) {
            return nullptr;
        }

        int i           = idx + n / 2;
        TreeNode* left  = treeBuilder(idx, i - idx);
        TreeNode* right = treeBuilder(i + 1, idx + n - i - 1);

        return new TreeNode(nums[i], left, right);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        this->nums      = nums;
        this->nums_size = nums.size();

        return treeBuilder(0, nums_size);
    }

    void inorderPrint(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        inorderPrint(root->left);

        cout << root->val << " ";

        inorderPrint(root->right);
    }

    void postorderClean(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        postorderClean(root->left);
        postorderClean(root->right);

        cout << root->val << " ";

        delete root;
    }
};

int main() {
    Solution S;

    // input
    vector<int> nums{-10, -3, 0, 5, 9};

    TreeNode* result = S.sortedArrayToBST(nums);

    S.inorderPrint(result);
    cout << endl;

    S.postorderClean(result);
    cout << endl;

    return 0;
}
