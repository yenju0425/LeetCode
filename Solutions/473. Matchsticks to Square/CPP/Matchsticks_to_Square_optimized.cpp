#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int target;
    int numOfMSs;
    vector<int> MSs;

public:
    bool squareGenarator(int idx, int side_len, int k) {
        if (k == 3) {  // if 3 sides is created successfully -> return true
            return true;
        }

        for (int i = idx; i < numOfMSs; i++) {
            if (MSs[i] <= 0 or (i > 0 and MSs[i - 1] == MSs[i])) {  // speed up
                continue;
            }

            int new_len = side_len + MSs[i];
            MSs[i] = -MSs[i];
            if (new_len < target and squareGenarator(idx + 1, new_len, k)) {
                return true;
            }
            if (new_len == target and squareGenarator(0, 0, k + 1)) {
                return true;
            }
            MSs[i] = -MSs[i];

            if (side_len == 0) {  // speed up
                return false;
            }
        }

        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;

        this->numOfMSs = matchsticks.size();
        for (int i = 0; i < numOfMSs; i++) {
            sum = sum + matchsticks[i];
        }
        if ((sum & 3) != 0) {  // sum % 4 must be "0"
            return false;
        }

        sort(matchsticks.begin(), matchsticks.end(), greater<int>());

        this->MSs = matchsticks;
        this->target = sum >> 2;  // side_len = sum / 4

        return squareGenarator(0, 0, 0);
    }
};

int main() {
    Solution* S = new Solution();

    // input
    vector<int> matchsticks{13, 11, 1, 8, 6, 7, 8, 8, 6, 7, 8, 9, 8};

    cout << S->makesquare(matchsticks) << endl;

    return 0;
}
