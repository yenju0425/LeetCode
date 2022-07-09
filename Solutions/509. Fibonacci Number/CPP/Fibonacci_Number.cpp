#include <iostream>

using namespace std;

class Solution{
public:
    int fib(int n){
        if(n < 2){
            return n;
        }

        int a = 0;
        int b = 1;
        for(int i = 2; i <= n; i++){
            a = a + b;
            swap(a, b);
        }

        return b;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    int n = 5;

    cout << S->fib(n) << endl;

    return 0;
}