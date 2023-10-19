#include <algorithm>
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
    TreeNode* treeBuilder(const vector<int>& inorder, const vector<int>& postorder, int inorder_begin, int inorder_end, int& postorder_index) {
        if (inorder_begin == inorder_end) {
            return nullptr;
        }

        int val = postorder[postorder_index];
        postorder_index--;

        TreeNode* node = new TreeNode(val);

        int inorder_index = distance(inorder.begin(), find(inorder.begin(), inorder.end(), val));

        node->right = treeBuilder(inorder, postorder, inorder_index + 1, inorder_end, postorder_index);
        node->left = treeBuilder(inorder, postorder, inorder_begin, inorder_index, postorder_index);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postorder_index = postorder.size() - 1;
        return treeBuilder(inorder, postorder, 0, inorder.size(), postorder_index);
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

    // input tree structure:
    //
    //    rt(3)
    //     |    \
    //    n1(9)  n2(0)
    //            |    \
    //           n4(5)  n5(7)

    vector<int> inorder{9, 3, 5, 0, 7};
    vector<int> postorder{9, 5, 7, 0, 3};

    TreeNode* result = S.buildTree(inorder, postorder);

    S.postorderClean(result);
    cout << endl;

    return 0;
}
