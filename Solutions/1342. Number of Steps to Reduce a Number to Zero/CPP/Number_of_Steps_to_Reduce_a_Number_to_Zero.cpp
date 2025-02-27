#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        if (num == 0) {
            return 0;
        }

        int numOf[2] = {0};
        while (num) {
            int bit    = num & 1;
            numOf[bit] = numOf[bit] + 1;
            num        = num >> 1;
        }

        return numOf[0] + numOf[1] * 2 - 1;
    }
};

int main() {
    Solution S;

    // input
    int num = 14;

    cout << S.numberOfSteps(num) << endl;

    return 0;
}
