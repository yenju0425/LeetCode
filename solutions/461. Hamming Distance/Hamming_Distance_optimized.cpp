#include <iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance = 0;
        x = x ^ y;
        while(x){
            distance += x & 1;
            x >>= 1;
        }
        return distance;
    }
};

int main(){
    Solution* S = new Solution();

    cout << S->hammingDistance(1, 4) << endl;

    return 0;
}