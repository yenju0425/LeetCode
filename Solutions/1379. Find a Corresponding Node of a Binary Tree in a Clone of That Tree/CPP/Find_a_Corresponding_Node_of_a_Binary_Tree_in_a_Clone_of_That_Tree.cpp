#include <iostream>

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
    TreeNode* getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target){
        if(original == nullptr){
            return nullptr;
        }
        else if(original == target){
            return cloned;
        }

        TreeNode *findLeft  = getTargetCopy(original->left,  cloned->left,  target);
        if(findLeft != nullptr){
            return findLeft;
        }
        TreeNode *findRight = getTargetCopy(original->right, cloned->right, target);
        if(findRight != nullptr){
            return findRight;
        }

        return nullptr;
    }
};

int main(){
    Solution *S = new Solution();

    //original
    TreeNode *node0 = new TreeNode(0);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node1 = new TreeNode(1, node0, nullptr);
    TreeNode *node4 = new TreeNode(4, node3, node5);
    TreeNode *root  = new TreeNode(2, node1, node4);

    //cloned
    TreeNode *_node0 = new TreeNode(0);
    TreeNode *_node3 = new TreeNode(3);
    TreeNode *_node5 = new TreeNode(5);
    TreeNode *_node1 = new TreeNode(1, _node0, nullptr);
    TreeNode *_node4 = new TreeNode(4, _node3, _node5);
    TreeNode *_root  = new TreeNode(2, _node1, _node4);

    cout << S->getTargetCopy(root, _root, node4) << endl;
    cout << "Real Target: " << _node4 << endl;

    return 0;
}