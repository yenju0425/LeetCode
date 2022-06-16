#include <iostream>

using namespace std;

class Solution{
public:
    int hammingWeight(uint32_t n){
        int counter = 0;
        while(n){
            counter = counter + (n & 1);
            n = n >> 1;
        }
        return counter;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    int n = 26;

    cout << S->hammingWeight(n) << endl;

    return 0;
}