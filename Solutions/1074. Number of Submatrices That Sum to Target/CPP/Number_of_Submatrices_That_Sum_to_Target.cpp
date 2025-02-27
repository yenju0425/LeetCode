#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int M = matrix.size();
        int N = matrix[0].size();

        for (int i = 0; i < M; i++) {
            for (int j = 1; j < N; j++) {
                matrix[i][j] = matrix[i][j] + matrix[i][j - 1];
            }
        }

        int result = 0;

        int sum = 0;
        unordered_map<int, int> UM;
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                sum = 0;
                UM  = {{0, 1}};
                for (int k = 0; k < M; k++) {
                    sum     = sum + matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
                    result  = result + UM[sum - target];
                    UM[sum] = UM[sum] + 1;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution S;

    int target = 0;
    vector<vector<int>> matrix{{0, 1, 0}, {1, 1, 1}, {0, 1, 0}};

    cout << S.numSubmatrixSumTarget(matrix, target) << endl;

    return 0;
}
