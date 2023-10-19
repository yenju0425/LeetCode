#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int M;
    int N;
    vector<vector<int>> grid;
    vector<vector<int>> dir;

public:
    bool isValid(int m, int n) {
        return m < M and m >= 0 and n < N and n >= 0;
    }

    int DFS(int m, int n) {
        int area = isValid(m, n) and grid[m][n];
        if (area) {
            grid[m][n] = 0;
            for (int i = 0; i < 4; i++) {
                area = area + DFS(m + dir[i][0], n + dir[i][1]);
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->M = grid.size();
        this->N = grid[0].size();
        this->grid = grid;
        this->dir = vector<vector<int>>{
            { 1,  0},
            { 0,  1},
            {-1,  0},
            { 0, -1}
        };

        int maxArea = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                maxArea = max(maxArea, DFS(i, j));
            }
        }

        return maxArea;
    }
};

int main() {
    Solution* S = new Solution();

    // input
    vector<vector<int>> grid{
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
    };

    cout << S->maxAreaOfIsland(grid) << endl;

    return 0;
}
