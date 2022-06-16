#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> DP(m, vector<int>(n, 0));

        //init first col
        for(int i = 0; i < m and obstacleGrid[i][0] == 0; i++){
            DP[i][0] = 1;
        }

        //init first row
        for(int i = 0; i < n and obstacleGrid[0][i] == 0; i++){
            DP[0][i] = 1;
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                DP[i][j] = !obstacleGrid[i][j] * (DP[i - 1][j] + DP[i][j - 1]);
            }
        }

        return DP[m - 1][n - 1];
    }
};

int main(){
    Solution *S = new Solution();

    //input
    vector<vector<int>> obstacleGrid{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    cout << S->uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}