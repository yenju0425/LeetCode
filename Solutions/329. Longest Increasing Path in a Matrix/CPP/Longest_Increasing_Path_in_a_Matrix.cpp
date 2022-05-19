#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    int m;
    int n;
    vector<vector<int>> M;
    vector<vector<int>> dp_len;
    vector<vector<bool>> visited;

public:
    bool isValid(int r, int c){
        return ((r < m and r >= 0) and (c < n and c >= 0)) ? true : false;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix){
        m = matrix.size();
        n = matrix[0].size();
        M       = matrix;
        dp_len  = vector<vector<int>>(m, vector<int>(n, -1));
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        int maxLength = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                maxLength = max(maxLength, LIP(vector<int>{i, j}));
            }
        }

        return maxLength;
    }

    int LIP(vector<int> pos){
        int r = pos[0];
        int c = pos[1];
        int x = dp_len[r][c];
        if(x != -1){
            return x;
        }
        
        //checking 4 directions
        int r_offset[4] = {-1,  0,  1,  0};
        int c_offset[4] = { 0,  1,  0, -1};

        dp_len[r][c] = 1;
        for(int i = 0; i < 4; i++){
            int row = r + r_offset[i];
            int col = c + c_offset[i];
            if(isValid(row, col) and M[r][c] < M[row][col]){
                dp_len[r][c] = max(dp_len[r][c], LIP(vector<int>{row, col}) + 1);
            }
        }

        return dp_len[r][c];
    }
};

int main(){
    Solution* S = new Solution();

    vector<vector<int>> m{
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };

    cout << S->longestIncreasingPath(m) << endl;

    return 0;
}