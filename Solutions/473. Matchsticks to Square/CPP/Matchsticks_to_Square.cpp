#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int numOfMSs;
    vector<int> MSs;
    int target;
    vector<int> side_len;

public:
    bool squareGenarator(int idx) {
        if (idx == numOfMSs) {
            return true;
        }

        bool findSquare = false;
        for (int i = 0; i < 4 and !findSquare; i++) {
            if (side_len[i] + MSs[idx] <= target) {
                side_len[i] = side_len[i] + MSs[idx];
                findSquare = squareGenarator(idx + 1);
                side_len[i] = side_len[i] - MSs[idx];

                if (side_len[i] == 0) {  // speed up
                    break;
                }
            }
        }

        return findSquare;
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
        this->side_len = vector<int>(4, 0);

        return squareGenarator(0);
    }
};

int main() {
    Solution* S = new Solution();

    // input
    vector<int> matchsticks{13, 11, 1, 8, 6, 7, 8, 8, 6, 7, 8, 9, 8};

    cout << S->makesquare(matchsticks) << endl;

    return 0;
}
