#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    int M;
    int N;
    vector<vector<int>> dir;
    vector<vector<vector<int>>> dp;

public:
    bool isValid(int m, int n){
        return m < M and m >= 0 and n < N and n >= 0;
    }

    int DFS(int m, int n, int k){
        if(!isValid(m, n)){
            return 1;
        }

        if(k >= 0){
            if(dp[m][n][k] == -1){
                unsigned int temp = 0;
                for(int i = 0; i < 4; i++){
                    temp = temp + DFS(m + dir[i][0], n + dir[i][1], k - 1);
                }

                temp = temp % 1000000007;
                dp[m][n][k] = temp;
            }

            return dp[m][n][k];
        }

        return 0;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn){
        this->M = m;
        this->N = n;
        this->dir         = vector<vector<int>>{{ 1,  0}, { 0,  1}, {-1,  0}, { 0, -1}};
        this->dp          = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(maxMove, -1)));

        return DFS(startRow, startColumn, maxMove - 1);
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    int m = 2;
    int n = 2;
    int maxMove     = 2;
    int startRow    = 0;
    int startColumn = 0;

    cout << S->findPaths(m, n, maxMove, startRow, startColumn) << endl;

    return 0;
}