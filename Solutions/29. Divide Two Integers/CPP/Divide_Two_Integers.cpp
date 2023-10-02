#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sameSign = ((dividend & INT_MIN) == (divisor & INT_MIN));

        unsigned int u_dividend = abs(dividend);
        unsigned int u_divisor  = abs(divisor);

        unsigned int buffer = 0;
        unsigned int result = 0;
        for(int i = 0; i < 32; ++i) { //32 bits
            buffer = (buffer << 1) + ((u_dividend & INT_MIN) == INT_MIN); //push_back the most significant bit of u_dividend
            u_dividend = u_dividend << 1;

            if(buffer >= u_divisor) {
                result = (result << 1) + 1;
                buffer = buffer - u_divisor;
            }
            else {
                result = result << 1;
            }
        }

        //overflow detection
        if(sameSign) {
            return (result == INT_MIN) ? result - 1 : result;
        }
        else {
            return ~result + 1;
        }
    }
};

int main() {
    Solution S;

    //inputs
    int dividend = -7;
    int divisor = 5;

    cout << S.divide(dividend, divisor) << endl;

    return 0;
}
