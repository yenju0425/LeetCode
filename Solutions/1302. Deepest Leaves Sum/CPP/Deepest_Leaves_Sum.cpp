#include <iostream>
#include <vector>
#include <queue>

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
public:
    int deepestLeavesSum(TreeNode* root){
        if(root == nullptr){
            return -1;
        }

        vector<queue<TreeNode*>> Q(2); //two Qs are needed

        int idx = 0;
        Q[idx].push(root);

        int levelSum;
        while(!Q[idx].empty()){
            levelSum = 0;
            int _idx = (idx + 1) % 2;
            while(!Q[idx].empty()){
                TreeNode* node = Q[idx].front();
                Q[idx].pop();
                levelSum = levelSum + node -> val;
                if(node -> left  != nullptr){
                    Q[_idx].push(node -> left);
                }
                if(node -> right != nullptr){
                    Q[_idx].push(node -> right);
                }
            }
            idx = _idx; //whitch to another Q
        }
        return levelSum;
    }
};

int main(){
    Solution *S = new Solution();

    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    TreeNode* node6 = new TreeNode(6);
    TreeNode* node7 = new TreeNode(7);
    TreeNode* node8 = new TreeNode(8);

    node1->left  = node2;
    node1->right = node3;

    node2->left  = node4;
    node2->right = node5;

    node3->right = node6;

    node4->left  = node7;

    node6->right = node8;

    cout << S->deepestLeavesSum(node1) << endl;
    return 0;
}