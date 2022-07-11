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
    vector<int> rightSideView(TreeNode *root){
        vector<int> result;
        vector<queue<TreeNode*>> Q(2);

        int idx = 0;
        if(root != nullptr){
            Q[idx].push(root);
        }

        while(!Q[idx].empty()){
            result.push_back(0); //resize "result"
            while(!Q[idx].empty()){
                TreeNode *node = Q[idx].front();
                Q[idx].pop();

                result.back() = node->val; //update

                if(node->left != nullptr){
                    Q[!idx].push(node->left);
                }
                if(node->right != nullptr){
                    Q[!idx].push(node->right);
                }
            }

            idx = !idx;
        }

        return result;
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

    vector<int> result = S->rightSideView(rt);

    for(auto i : result){
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}