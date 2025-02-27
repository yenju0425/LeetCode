#include <iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance = 0;
        x            = x ^ y;
        while (x) {
            distance += x & 1;
            x >>= 1;
        }
        return distance;
    }
};

int main() {
    Solution S;

    int x = 1;
    int y = 4;

    cout << S.hammingDistance(x, y) << endl;

    return 0;
}
