#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k){
        int m = grid.size();
        int n = grid[0].size();

        vector<int> temp(m, 0);

        while(k > 0){
            for(int i = 0; i < m; i = i + 1){
                temp[i] = grid[i][n-1];
            }

            for(int j = n - 1; j > 0; j = j - 1){ //j = n - 1 -> 1
                for(int i = 0; i < m; i = i + 1){ //i = 0     -> m
                    grid[i][j] = grid[i][j - 1];
                }
            }

            for(int i = 0; i < m; i = i + 1){
                grid[i][0] = temp[(i + m - 1) % m];
            }
            k = k - 1;
        }

        return grid;
    }
};

int main(){
    Solution* S = new Solution();
    
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