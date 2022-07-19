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

        vector<queue<TreeNode*>> Q(2);

        int idx = 0;
        Q[idx].push(root);

        int levelSum;
        while(!Q[idx].empty()){
            levelSum = 0;
            while(!Q[idx].empty()){
                TreeNode *node = Q[idx].front();
                Q[idx].pop();
                levelSum = levelSum + node -> val;
                if(node -> left  != nullptr){
                    Q[!idx].push(node -> left);
                }
                if(node -> right != nullptr){
                    Q[!idx].push(node -> right);
                }
            }
            idx = !idx; //whitch to another Q
        }

        return levelSum;
    }
};

int main(){
    Solution *S = new Solution();

    //input tree structure:
    //
    //    rt(2)
    //    |     \
    //    n1(1)  n2(4)
    //    |      |     \
    //    n3(0)  n4(3)  n5(5)
    //
    TreeNode *n5 = new TreeNode(5);
    TreeNode *n4 = new TreeNode(3);
    TreeNode *n3 = new TreeNode(0);
    TreeNode *n2 = new TreeNode(4, n4, n5);
    TreeNode *n1 = new TreeNode(1, n3, nullptr);
    TreeNode *rt = new TreeNode(2, n1, n2);

    cout << S->deepestLeavesSum(rt) << endl;

    return 0;
}