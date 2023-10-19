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
    TreeNode* treeBuilder(const vector<int>& preorder, const vector<int>& inorder, int inorder_begin, int inorder_end, int& preorder_index) {
        if (inorder_begin == inorder_end) {
            return nullptr;
        }

        int val = preorder[preorder_index];
        preorder_index++;

        TreeNode* node = new TreeNode(val);

        int inorder_index = distance(inorder.begin(), find(inorder.begin(), inorder.end(), val));

        node->left = treeBuilder(preorder, inorder, inorder_begin, inorder_index, preorder_index);
        node->right = treeBuilder(preorder, inorder, inorder_index + 1, inorder_end, preorder_index);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorder_index = 0;
        return treeBuilder(preorder, inorder, 0, inorder.size(), preorder_index);
    }

    void cleanTree(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        cleanTree(root->left);
        cleanTree(root->right);

        cout << root->val << " ";

        delete root;
    }
};

int main() {
    Solution S;

    // input tree structure:
    //
    //     rt(3)
    //     |     \
    //    n1(9)  n2(0)
    //            |     \
    //           n4(5)  n5(7)
    //
    vector<int> preorder{3, 9, 0, 5, 7};
    vector<int> inorder{9, 3, 5, 0, 7};

    TreeNode* result = S.buildTree(preorder, inorder);

    S.cleanTree(result);
    cout << endl;

    return 0;
}
