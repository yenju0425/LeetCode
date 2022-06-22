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
private:
    int nums_size;
    vector<int> nums;

public:
    TreeNode* growTrees(int idx, int n){
        if(n == 0){
            return nullptr;
        }

        int i = idx + n / 2;
        TreeNode *left  = growTrees(idx,   i - idx);
        TreeNode *right = growTrees(i + 1, idx + n - i - 1);

        return new TreeNode(nums[i], left, right);
    }

    TreeNode* sortedArrayToBST(vector<int> &nums){
        this->nums      = nums;
        this->nums_size = nums.size();

        return growTrees(0, nums_size);
    }
};

void BFS_levelorder(TreeNode *root){
    vector<queue<TreeNode*>> Q(2);

    int idx = 0;
    if(root != nullptr){
        Q[idx].push(root);
    }
    while(!Q[idx].empty()){
        while(!Q[idx].empty()){
            TreeNode *node = Q[idx].front();
            Q[idx].pop();

            if(node == nullptr){
                cout << "# ";
            }
            else{
                cout << node->val << ' ';
                Q[!idx].push(node->left);
                Q[!idx].push(node->right);
            }
        }

        idx = !idx;
        cout << "| ";
    }

    cout << endl;
}

int main(){
    Solution *S = new  Solution();

    //input
    vector<int> nums{-10, -3, 0, 5, 9};
    
    TreeNode* result = S->sortedArrayToBST(nums);

    BFS_levelorder(result);

    return 0;
}