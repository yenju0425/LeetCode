#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n > 0) {
            double temp = 1;
            while (n) {
                if (n & 1 == 1) {
                    temp = temp * x;
                }
                x = x * x;
                n = n >> 1;
            }
            return temp;
        }
        else if (n < 0) {
            if (x == 0) {
                return 0;
            }
            double temp = 1;
            long ln = -long(n);
            while (ln) {
                if (ln & 1 == 1) {
                    temp = temp * x;
                }
                x = x * x;
                ln = ln >> 1;
            }
            return double(1 / temp);
        }

        else {  // n == 0
            return 1;
        }
    }
};

int main() {
    Solution S;

    // inputs
    double x = 5;
    int n = -2;

    cout << S.myPow(x, n) << endl;

    return 0;
}
