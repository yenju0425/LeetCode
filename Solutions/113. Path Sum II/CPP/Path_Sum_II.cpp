#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

class Solution{
private:
    vector<int> path;
    vector<vector<int>> paths;

public:
    void pathFinder(TreeNode *node, int targetSum){
        if(node == nullptr){
            return;
        }

        if(node->left == nullptr and node->right == nullptr){
            if(node->val == targetSum){
                path.push_back(node->val);
                paths.push_back(path);
                path.pop_back();
                return;
            }
        }

        int newTargetSum = targetSum - node->val;
        if(node->left != nullptr){
            path.push_back(node->val);
            pathFinder(node->left,  newTargetSum);
            path.pop_back();
        }
        if(node->right != nullptr){
            path.push_back(node->val);
            pathFinder(node->right, newTargetSum);
            path.pop_back();
        }
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum){
        pathFinder(root, targetSum);
        return paths;
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    int targetSum = 7;

    //input tree structure:
    //
    //    rt(0)
    //    |     \
    //    n1(1)  n2(2)
    //    |      |     \
    //    n3(3)  n4(4)  n5(5)
    //
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n2 = new TreeNode(2, n4, n5);
    TreeNode *n1 = new TreeNode(1, n3, nullptr);
    TreeNode *rt = new TreeNode(0, n1, n2);

    vector<vector<int>> result = S->pathSum(rt, targetSum);

    for(auto i : result){
        for(auto j : i){
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}