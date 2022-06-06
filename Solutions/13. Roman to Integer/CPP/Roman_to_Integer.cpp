#include <iostream>
#include <map>

using namespace std;

class Solution{
private:
    map<char, int> romanNum{
        {'M', 1000},
        {'D', 500},
        {'C', 100},
        {'L', 50},
        {'X', 10},
        {'V', 5},
        {'I', 1}
    };

public:
    int romanToInt(string s){
        int sum = romanNum[s[0]];

        for(string::iterator iter = s.begin() + 1; iter != s.end(); iter = iter + 1){
            if(romanNum[*(iter - 1)] < romanNum[*iter]){
                sum = sum - 2 * romanNum[*(iter - 1)] + romanNum[*iter];
            }
            else{
                sum = sum + romanNum[*iter];
            }
        }

        return sum;
    }
};

int main(){
    Solution* S = new Solution();

    //input
    string s = "MCMLXXXVII";

    cout << S->romanToInt(s) << endl;

    return 0;
}