#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
    }
};

int main(){
    vector<vector<int>> grid{
        {0, 0, 0},
        {1, 0, 1},
        {0, 0, 0}
    };

    Solution* S = new Solution();
    
    cout << S->shortestPathBinaryMatrix(grid) << endl;

    return 0;
}