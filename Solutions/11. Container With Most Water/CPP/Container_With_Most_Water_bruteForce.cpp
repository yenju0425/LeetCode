#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int currentMax = 0;

        int height_size = height.size();
        for (int i = 0; i < height_size - 1; ++i) {
            for (int j = i + 1; j < height_size; ++j) {
                int area = min(height[i], height[j]) * (j - i);
                currentMax = max(currentMax, area);
            }
        }

        return currentMax;
    }
};

int main() {
    Solution S;

    // input
    vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << S.maxArea(height) << endl;

    return 0;
}
