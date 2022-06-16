#include <iostream>

using namespace std;

class Solution{
public:
    int countVowelStrings(int n){
        return (n + 1) * (n + 2) * (n + 3) * (n + 4) / 24;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    int n = 33;

    cout << S->countVowelStrings(n) << endl;

    return 0;
}