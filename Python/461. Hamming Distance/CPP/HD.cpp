#include <iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance = 0;
        while(x != 0 or y != 0){
            distance = distance + abs(x % 2 - y % 2);
            x = x / 2;
            y = y / 2;
        }
        return distance;
    }
};

int main(){
    Solution* S = new Solution();

    cout << S->hammingDistance(1, 4) << endl;

    return 0;
}