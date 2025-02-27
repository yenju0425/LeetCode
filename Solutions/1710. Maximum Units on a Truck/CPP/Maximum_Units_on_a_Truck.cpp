#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(vector<int>& a, vector<int>& b) { return a[1] > b[1]; }

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);

        int units = 0;
        for (int i = 0; i < boxTypes.size() and truckSize > 0; i++) {
            int numOfBoxes = min(truckSize, boxTypes[i][0]);
            units          = units + boxTypes[i][1] * numOfBoxes;
            truckSize      = truckSize - numOfBoxes;
        }

        return units;
    }
};

int main() {
    Solution S;

    int truckSize = 10;
    vector<vector<int>> boxTypes{{5, 10}, {2, 5}, {4, 7}, {3, 9}};

    cout << S.maximumUnits(boxTypes, truckSize) << endl;

    return 0;
}
