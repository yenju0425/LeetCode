#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
};

class Solution{
public:
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> levels;
        vector<queue<TreeNode*>> Q(2); //two queues are neeeded
        int idx = 0;
        if(root != nullptr){
            Q[idx].push(root);
        }
        while(!Q[idx].empty()){
            int _idx = (idx + 1) % 2; //_idx: another queue's index
            vector<int> level;
            while(!Q[idx].empty()){
                TreeNode* node = Q[idx].front();
                Q[idx].pop();
                level.push_back(node->val);
                if(node->left != nullptr){
                    Q[_idx].push(node->left);
                }
                if(node->right != nullptr){
                    Q[_idx].push(node->right);
                }
            }
            levels.push_back(level);
            idx = _idx; //switch to another Q
        }
        return levels;
    }
};

int main(){
    Solution *S = new Solution();
    TreeNode* node0 = new TreeNode(0);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node5 = new TreeNode(5);
    
    TreeNode* node1 = new TreeNode(1, node0, nullptr);
    TreeNode* node4 = new TreeNode(4, node3, node5);

    TreeNode* root  = new TreeNode(2, node1, node4);

    cout << "levelorder  : " << endl;
    vector<vector<int>> ans = S->levelOrder(root);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}