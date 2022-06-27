#include <iostream>

using namespace std;

class Solution{
public:
    int minPartitions(string n){
        int maxInt = 0;
        for(string::iterator iter = n.begin(); iter != n.end(); iter++){
            maxInt = max(maxInt, *iter - '0');
        }

        return maxInt;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    string n = "1987";

    cout << S->minPartitions(n) << endl;

    return 0;
}