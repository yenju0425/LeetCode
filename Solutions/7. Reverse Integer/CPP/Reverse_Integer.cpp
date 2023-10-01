#include <iostream>

using namespace std;

class Solution{
public:
    bool addDigit(int &reversed_n, int &n){
        if(reversed_n > 214748364 or reversed_n < -214748364){
            return true;
        }

        int temp = reversed_n * 10;
        reversed_n = temp + n % 10;
        n = n / 10;

        if((reversed_n > 0 and temp < 0) or (reversed_n < 0 and temp > 0)){
            return true;
        }

        return false; //no overflow detected
    }

    int reverse(int x){
        int reversed_x = x % 10;
        x = x / 10;

        while(x != 0){
            if(addDigit(reversed_x, x)){ //"true" if overflow detected
                return 0;
            }
        }

        return reversed_x;
    }
};

int main(){
    Solution S;

    //input
    int x = -123;

    cout << S.reverse(x) << endl;

    return 0;
}
