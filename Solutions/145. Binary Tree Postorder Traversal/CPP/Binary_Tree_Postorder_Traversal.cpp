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
    void concatenate(vector<int>& target, vector<int> source) {
        for (int i = 0; i < source.size(); i++) {
            target.push_back(source[i]);
        }
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if (root == nullptr) {
            return postorder;
        }
        concatenate(postorder, postorderTraversal(root->left));
        concatenate(postorder, postorderTraversal(root->right));
        concatenate(postorder, vector<int>{root->val});
        return postorder;
    }
};

int main() {
    Solution* S = new Solution();

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

    vector<int> result = S->postorderTraversal(rt);

    for (auto i : result) {
        cout << i << ' ';
    }

    return 0;
}
