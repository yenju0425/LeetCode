#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int& target) {
        int M    = matrix.size();
        int N    = matrix[0].size();
        int m    = 0;
        int n    = N - 1;
        int size = M + N;
        for (int i = 0; i < size && m < M && n >= 0; i++) {
            if (matrix[m][n] > target) {
                n = n - 1;
            } else if (matrix[m][n] < target) {
                m = m + 1;
            } else {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution S;

    int target = 7;
    vector<vector<int>> matrix{{1, 4, 7}};

    cout << S.searchMatrix(matrix, target) << endl;

    return 0;
}
