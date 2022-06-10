#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    int m;
    int n;
    vector<vector<int>> M;
    vector<vector<int>> dp_len;

public:
    bool isValid(int r, int c){
        return ((r < m and r >= 0) and (c < n and c >= 0)) ? true : false;
    }

    int longestIncreasingPath(vector<vector<int>> &matrix){
        m = matrix.size();
        n = matrix[0].size();
        M       = matrix;
        dp_len  = vector<vector<int>>(m, vector<int>(n, -1));

        int maxLength = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                maxLength = max(maxLength, LIP(i, j));
            }
        }

        return maxLength;
    }

    int LIP(int row, int col){
        int x = dp_len[row][col];
        if(x != -1){
            return x;
        }
        
        //checking 4 directions
        int row_offset[4] = {-1,  0,  1,  0};
        int col_offset[4] = { 0,  1,  0, -1};

        int maxLength = 1;
        for(int i = 0; i < 4; i++){
            int r = row + row_offset[i];
            int c = col + col_offset[i];
            if(isValid(r, c) and M[row][col] < M[r][c]){
                maxLength = max(maxLength, LIP(r, c) + 1);
            }
        }

        dp_len[row][col] = maxLength;

        return maxLength;
    }
};

int main(){
    Solution* S = new Solution();

    //input
    vector<vector<int>> matrix{
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };

    cout << S->longestIncreasingPath(matrix) << endl;

    return 0;
}