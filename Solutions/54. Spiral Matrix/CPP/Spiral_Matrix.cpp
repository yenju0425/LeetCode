#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        int M = matrix.size();
        int N = matrix[0].size();

        int m; //row index
        int n; //col index

        int numOfIter = min(M + 1, N + 1) / 2;
        for(int i = 0; i < numOfIter; ++i) {
            //init m, n
            m = i;
            n = i;
    
            //push back first element
            result.push_back(matrix[m][n]);

            //go right N - 1 steps
            for(int j = 1; j < N; ++j) {
                n = n + 1;
                result.push_back(matrix[m][n]);
            }

            //go down M - 1 steps
            for(int j = 1; j < M; ++j) {
                m = m + 1;
                result.push_back(matrix[m][n]);
            }

            //go left N - 1 steps
            for(int j = 1; j < N && M > 1; ++j) {
                n = n - 1;
                result.push_back(matrix[m][n]);
            }

            //go up M - 2 steps
            for(int j = 2; j < M && N > 1; ++j) {
                m = m - 1;
                result.push_back(matrix[m][n]);
            }

            //update M, N
            M = M - 2;
            N = N - 2;
        }

        return result;
    }
};

int main() {
    Solution S;

    //input
    vector<vector<int>> matrix {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 0, 1, 2},
        {9, 0, 1, 2}
    };

    vector<int> result = S.spiralOrder(matrix);

    for(auto i : result) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
