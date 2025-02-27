#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;

        vector<vector<int>> S;  // stack

        int heights_size = heights.size();
        for (int i = 0; i < heights_size; ++i) {
            int temp = i;

            while (!S.empty() && S.back()[0] > heights[i]) {
                temp    = S.back()[1];
                maxArea = max(maxArea, S.back()[0] * (i - S.back()[1]));
                S.pop_back();
            }

            S.push_back(vector<int>{heights[i], temp});
        }

        int size = S.size();
        for (int i = 0; i < size; ++i) {
            maxArea = max(maxArea, S[i][0] * (heights_size - S[i][1]));
        }

        return maxArea;
    }
};

int main() {
    Solution S;

    // input
    vector<int> heights{2, 1, 5, 6, 2, 3};

    cout << S.largestRectangleArea(heights) << endl;

    return 0;
}
