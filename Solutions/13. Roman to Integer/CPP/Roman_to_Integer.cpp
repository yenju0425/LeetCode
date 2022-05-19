#include <iostream>
#include <map>

using namespace std;

class Solution{
public:
    int romanToInt(string s){
        map<char, int> romanNum;
        romanNum['M'] = 1000;
        romanNum['D'] = 500;
        romanNum['C'] = 100;
        romanNum['L'] = 50;
        romanNum['X'] = 10;
        romanNum['V'] = 5;
        romanNum['I'] = 1;

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

    cout << S->romanToInt("MCMVII") << endl;

    return 0;
}