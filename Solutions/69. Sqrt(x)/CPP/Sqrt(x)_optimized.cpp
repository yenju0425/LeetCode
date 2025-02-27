#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long i = 0;

        // slow start method
        int step = 1;
        while (true) {
            i = i + step;
            if (i * i <= x) {
                step = max(step + 1, 16);
            } else {
                if (step != 1) {
                    i    = i - step;
                    step = 1;
                } else {
                    return i - 1;
                }
            }
        }
    }
};

int main() {
    Solution S;

    // input
    int x = 8;

    cout << S.mySqrt(x) << endl;

    return 0;
}
