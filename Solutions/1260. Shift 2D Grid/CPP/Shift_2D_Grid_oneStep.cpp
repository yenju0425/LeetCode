#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int M = grid.size();
        int N = grid[0].size();

        vector<vector<int>> newGrid(M, vector<int>(N, 0));

        for (int i = 0; i < M; i = i + 1) {
            for (int j = 0; j < N; j = j + 1) {
                k = k % (M * N);

                int m = k / N;
                int n = k % N;

                newGrid[m][n] = grid[i][j];

                k = k + 1;
            }
        }
        return newGrid;
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
