#include <iostream>

using namespace std;

class Solution{
public:
    int mySqrt(int x){
        long i = 1;
        while(i * i <= x){
            i = i + 1;
        }
        return i - 1;
    }
};

int main(){
    Solution* S = new Solution();
    
    //input
    int x = 8;

    cout << S->mySqrt(x) << endl;

    return 0;
}