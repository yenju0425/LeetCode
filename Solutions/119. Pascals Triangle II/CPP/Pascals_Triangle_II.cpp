#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> PascalsTriangle;

        PascalsTriangle.push_back(vector<int>{1});

        for (int i = 1; i <= rowIndex; i++) {
            vector<int> newRow(i + 1, 1);

            for (int j = 1; j < i; j++) {
                newRow[j] = PascalsTriangle[i - 1][j] + PascalsTriangle[i - 1][j - 1];
            }

            PascalsTriangle.push_back(newRow);
        }

        return PascalsTriangle.back();
    }
};

int main() {
    Solution S;

    // input
    int rowIndex = 3;

    vector<int> result = S.getRow(rowIndex);

    for (auto i : result) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
