#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        return *max_element(n.begin(), n.end()) - '0';
    }
};

int main(){
    Solution *S = new Solution();

    //input
    string n = "1987";

    cout << S->minPartitions(n) << endl;

    return 0;
}