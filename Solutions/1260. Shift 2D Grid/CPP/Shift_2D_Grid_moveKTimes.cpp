#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int M = grid.size();
        int N = grid[0].size();

        vector<int> temp(M, 0);

        while (k > 0) {
            for (int i = 0; i < M; i = i + 1) {
                temp[i] = grid[i][N - 1];
            }

            for (int j = N - 1; j > 0; j = j - 1) {  // j = N - 1 -> 1
                for (int i = 0; i < M; i = i + 1) {  // i = 0     -> M
                    grid[i][j] = grid[i][j - 1];
                }
            }

            for (int i = 0; i < M; i = i + 1) {
                grid[i][0] = temp[(i + M - 1) % M];
            }
            k = k - 1;
        }

        return grid;
    }
};

int main() {
    Solution* S = new Solution();

    // inputs
    int k = 1;
    vector<vector<int>> grid{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    vector<vector<int>> result = S->shiftGrid(grid, k);

    for (auto i : grid) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}
