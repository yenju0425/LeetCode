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
    //inputs
    Solution *S = new Solution();
    string number = "81235038532348435348983";
    char digit = '8';

    cout << "Original number:" << number << endl;
    cout << "Modified number:" << S->removeDigit(number, digit) << endl;

    return 0;
}
