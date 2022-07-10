#include <iostream>

using namespace std;

class Solution{
public:
    string removeDigit(string number, char digit){
        string::iterator rmDigit;

        for(string::iterator iter = number.begin(); iter != number.end(); iter++){
            if(*iter == digit){
                rmDigit = iter;
                if(*(iter + 1) > digit){
                    break;
                }
            }
        }

        number.erase(rmDigit);

        return number;
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    string number = "81235038532348435348983";
    char digit = '8';

    cout << "Original number:" << number << endl;
    cout << "Modified number:" << S->removeDigit(number, digit) << endl;

    return 0;
}
