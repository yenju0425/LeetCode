#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
private:
    map<int, int> numCount;

public:
    int numIdenticalPairs(vector<int>& nums) {
        for (const int& num : nums) {
            numCount[num]++;
        }

        int numPairs = 0;
        for (auto& pair : numCount) {
            int count = pair.second;
            // numPairs += (count >= 2) ? (count * (count - 1) / 2) : 0;
            numPairs += (count >= 2) ? (count * (count - 1) >> 1) : 0;
        }

        return numPairs;
    }
};

int main() {
    Solution S;

    //input
    vector<int> nums{1, 2, 3, 1, 1, 3};

    cout << S.numIdenticalPairs(nums) << endl;

    return 0;
}
