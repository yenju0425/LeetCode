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
    int* DFS(TreeNode* root) {
        //
        //    result[0]: num of bulbs to light up the whole tree while using the root
        //    result[1]: num of bulbs to light up the whole tree without using the root
        //    result[2]: will light up the whole tree if we put a light at root's parent node
        //
        int* result = new int[3]{0};

        if (root == nullptr) {
            return result;
        }

        int* left  = DFS(root->left);
        int* right = DFS(root->right);

        // set result[0]
        result[0] = min(left[0], min(left[1], left[2])) + min(right[0], min(right[1], right[2])) + 1;

        // set result[1]
        int leftChild  = (left[0] == 0) ? INT_MAX : left[0] + min(right[0], right[1]);
        int rightChild = (right[0] == 0) ? INT_MAX : right[0] + min(left[0], left[1]);
        result[1]      = min(leftChild, rightChild);

        // set result[2]
        result[2] = (left[1] == INT_MAX or right[1] == INT_MAX) ? INT_MAX : left[1] + right[1];

        return result;
    }

    int minCameraCover(TreeNode* root) {
        int* result = DFS(root);
        return min(result[0], result[1]);
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

    cout << S.minCameraCover(rt) << endl;

    return 0;
}
