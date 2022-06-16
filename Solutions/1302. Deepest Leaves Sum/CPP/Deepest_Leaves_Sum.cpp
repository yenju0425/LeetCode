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
    int deepestLeavesSum(TreeNode *root){
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
                TreeNode *node = Q[idx].front();
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

    //level 3
    TreeNode *node8 = new TreeNode(8);
    TreeNode *node7 = new TreeNode(7);
    
    //level 2
    TreeNode *node6 = new TreeNode(6, nullptr, node8);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node4 = new TreeNode(4, node7,   nullptr);

    //level 1
    TreeNode *node3 = new TreeNode(3, nullptr, node6);
    TreeNode *node2 = new TreeNode(2, node4,   node5);

    //level 0
    TreeNode *node1 = new TreeNode(1, node2, node3);

    cout << S->deepestLeavesSum(node1) << endl;

    return 0;
}