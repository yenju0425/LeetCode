#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int numOfLPs = 0;

        int x_min = INT_MAX;
        int x_max = INT_MIN;
        int y_min = INT_MAX;
        int y_max = INT_MIN;

        int circles_size = circles.size();
        for (int i = 0; i < circles_size; i++) {
            x_min = min(x_min, circles[i][0] - circles[i][2]);
            x_max = max(x_max, circles[i][0] + circles[i][2]);
            y_min = min(y_min, circles[i][1] - circles[i][2]);
            y_max = max(y_max, circles[i][1] + circles[i][2]);
        }

        // check every point in the rectangle
        int x, y, r;
        for (int i = x_min; i <= x_max; i++) {
            for (int j = y_min; j <= y_max; j++) {
                for (int c = 0; c < circles_size; c++) {
                    x = circles[c][0] - i;
                    y = circles[c][1] - j;
                    r = circles[c][2];
                    if (x * x + y * y <= r * r) {
                        numOfLPs = numOfLPs + 1;
                        break;
                    }
                }
            }
        }

        return numOfLPs;
    }
};

int main() {
    Solution* S = new Solution();

    // input
    vector<vector<int>> ciecles{
        {2, 2, 2}};

    cout << S->countLatticePoints(ciecles) << endl;

    return 0;
}
