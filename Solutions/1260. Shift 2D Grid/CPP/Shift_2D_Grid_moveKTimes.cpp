#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k){
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
    vector<vector<int>> vect{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution* S = new Solution();

    vect = S->shiftGrid(vect, 1);

    int m = vect.size();
    int n = vect[0].size();
    for(int i = 0; i < m; i = i + 1){
        for(int j = 0; j < n; j = j + 1){
            cout << vect[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}