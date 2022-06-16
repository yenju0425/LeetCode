#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k){
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> newGrid(m, vector<int>(n, 0));
 
        for(int i = 0; i < m; i = i + 1){
            for(int j = 0; j < n; j = j + 1){
                k = k % (m  *n);

                int m_index = k / n;
                int n_index = k % n;
                
                newGrid[m_index][n_index] = grid[i][j];

                k = k + 1;
            }
        }
        return newGrid;
    }
};

int main(){
    Solution *S = new Solution();
    
    //inputs
    int k = 1;
    vector<vector<int>> grid{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<int>> result = S->shiftGrid(grid, k);

    for(auto i : grid){
        for(auto j : i){
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}