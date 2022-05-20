#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    int M;
    int N;
    vector<vector<int>> numOfUniquePath;

public:
    bool isValid(int m, int n){
        return ((m < M and m >= 0) and (n < N and n >= 0)) ? true : false;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        M = obstacleGrid.size();
        N = obstacleGrid[0].size();

        numOfUniquePath = vector<vector<int>>(M, vector<int>(N, 0));
        numOfUniquePath[0][0] = (obstacleGrid[0][0] + 1) % 2;

        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(obstacleGrid[i][j] == 1){
                    continue;
                }
                if(isValid(i - 1, j)){
                    numOfUniquePath[i][j] = numOfUniquePath[i - 1][j];
                }
                if(isValid(i, j - 1)){
                    numOfUniquePath[i][j] = numOfUniquePath[i][j] + numOfUniquePath[i][j - 1];
                }
            }
        }

        return numOfUniquePath[M - 1][N - 1];
    }
};

int main(){
    Solution* S = new Solution();

    vector<vector<int>> obstacleGrid{
        {0, 0, 1},
        {1, 0, 0}
    };

    cout << S->uniquePathsWithObstacles(obstacleGrid) << endl;

    return 0;
}