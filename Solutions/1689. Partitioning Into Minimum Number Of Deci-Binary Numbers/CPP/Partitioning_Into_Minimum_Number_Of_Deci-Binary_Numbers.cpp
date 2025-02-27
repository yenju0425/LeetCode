#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minPartitions(string n) { return *max_element(n.begin(), n.end()) - '0'; }
};

int main() {
    Solution S;

    // input
    string n = "1987";

    cout << S.minPartitions(n) << endl;

    return 0;
}
