#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    int M;
    int N;
    vector<vector<int>> matrix;
    vector<vector<int>> dp;
    vector<vector<int>> dir;

public:
    bool isValid(int m, int n){
        return m < M and m >= 0 and n < N and n >= 0;
    }

    int LIP(int m, int n){
        if(dp[m][n] == 0){
            int maxLength = 0;
            for(int i = 0; i < 4; i++){
                int m_ = m + dir[i][0];
                int n_ = n + dir[i][1];
                if(isValid(m_, n_) and matrix[m][n] < matrix[m_][n_]){
                    maxLength = max(maxLength, LIP(m_, n_));
                }
            }

            dp[m][n] = maxLength + 1;
        }

        return dp[m][n];
    }

    int longestIncreasingPath(vector<vector<int>> &matrix){
        this->M = matrix.size();
        this->N = matrix[0].size();
        this->matrix = matrix;
        this->dp = vector<vector<int>>(M, vector<int>(N, 0));
        this->dir = vector<vector<int>>{{ 1,  0}, { 0,  1}, {-1,  0}, { 0, -1}};

        int maxLength = 0;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                maxLength = max(maxLength, LIP(i, j));
            }
        }

        return maxLength;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    vector<vector<int>> matrix{
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };

    cout << S->longestIncreasingPath(matrix) << endl;

    return 0;
}