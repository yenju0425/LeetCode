#include <iostream>

using namespace std;

class Solution{
public:
    string removeDigit(string number, char digit){
        string::iterator rmDigit;
        for(string::iterator i = number.begin(); i != number.end(); i++){
            if(*i == digit){
                if(*(i + 1) > digit){
                    number.erase(i);
                    return number;
                }
                else{
                    rmDigit = i;
                }
            }
        }
        number.erase(rmDigit);
        return number;
    }
};

int main(){
    string ss = "81235038532348435348983";

    Solution* S = new Solution();

    cout << S->removeDigit(ss, '8') << endl;
    cout << ss << endl;

    return 0;
}
