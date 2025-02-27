#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        // get max_h
        horizontalCuts.push_back(h);
        sort(horizontalCuts.begin(), horizontalCuts.end());

        int max_h  = horizontalCuts[0];
        int h_size = horizontalCuts.size();
        for (int i = 1; i < h_size; i++) {
            max_h = max(max_h, horizontalCuts[i] - horizontalCuts[i - 1]);
        }

        // get max_v
        verticalCuts.push_back(w);
        sort(verticalCuts.begin(), verticalCuts.end());

        int max_v  = verticalCuts[0];
        int v_size = verticalCuts.size();
        for (int i = 1; i < v_size; i++) {
            max_v = max(max_v, verticalCuts[i] - verticalCuts[i - 1]);
        }

        return (1ULL * max_h * max_v) % 1000000007;
    }
};

int main() {
    Solution S;

    int h = 5;
    int w = 4;
    vector<int> horizontalCuts{1, 2, 4};
    vector<int> verticalCuts{1, 3};

    cout << S.maxArea(h, w, horizontalCuts, verticalCuts) << endl;

    return 0;
}
