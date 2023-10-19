#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct cmp {
    bool operator()(const vector<int>& pair, const int& val) {
        return (pair.back() < val);
    }
    bool operator()(const int& val, const vector<int>& pair) {
        return (val < pair.back());
    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // look for the row that contains the target
        vector<vector<int>>::iterator target_row = lower_bound(matrix.begin(), matrix.end(), target, cmp());

        // perform binary_search
        return (target_row == matrix.end()) ? false : binary_search(target_row->begin(), target_row->end(), target);
    }
};

int main() {
    Solution* S = new Solution();

    // inputs
    int target = 34;
    vector<vector<int>> matrix{
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};

    cout << S->searchMatrix(matrix, target) << endl;

    return 0;
}
