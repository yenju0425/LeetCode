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
    vector<vector<int>> levelOrder(TreeNode *root){
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
                TreeNode *node = Q[idx].front();
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

    vector<vector<int>> result = S->levelOrder(rt);

    for(auto i : result){
        for(auto j : i){
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}