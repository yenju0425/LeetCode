#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // calculate path sum
        int depth = triangle.size();
        for (int i = 1; i < depth; i++) {
            triangle[i][0] = triangle[i][0] + triangle[i - 1][0];
            for (int j = 1; j < i; j++) {
                triangle[i][j] = triangle[i][j] + min(triangle[i - 1][j], triangle[i - 1][j - 1]);
            }
            triangle[i][i] = triangle[i][i] + triangle[i - 1][i - 1];
        }

        // look for the minimum path sum
        int result = INT_MAX;
        for (int i = 0; i < depth; i++) {
            result = min(result, triangle[depth - 1][i]);
        }

        return result;
    }
};

int main() {
    Solution* S = new Solution();

    // input
    vector<vector<int>> triangle{
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };

    cout << S->minimumTotal(triangle) << endl;

    return 0;
}
