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
public:
    vector<TreeNode*> generateTreesHelper(int idx, int n) {
        if (n == 0) {
            return vector<TreeNode*>{nullptr};
        }

        vector<TreeNode*> trees;
        for (int i = idx; i < idx + n; ++i) {
            vector<TreeNode*> left  = generateTreesHelper(idx, i - idx);
            vector<TreeNode*> right = generateTreesHelper(i + 1, n + idx - i - 1);

            for (auto l : left) {
                for (auto r : right) {
                    TreeNode* tree = new TreeNode(i, l, r);
                    trees.push_back(tree);
                }
            }
        }

        return trees;
    }

    vector<TreeNode*> generateTrees(int n) {
        return generateTreesHelper(1, n);
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
    int n = 3;

    vector<TreeNode*> result = S.generateTrees(n);

    for (auto i : result) {
        S.postorderClean(i);
        cout << endl;
    }

    return 0;
}
