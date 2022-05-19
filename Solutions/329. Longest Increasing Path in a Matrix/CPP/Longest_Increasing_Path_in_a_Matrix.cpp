#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
    }
};

int main(){
    Solution* S = new Solution();

    vector<vector<int>> M{
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };

    cout << S->longestIncreasingPath(M) << endl;

    return 0;
}