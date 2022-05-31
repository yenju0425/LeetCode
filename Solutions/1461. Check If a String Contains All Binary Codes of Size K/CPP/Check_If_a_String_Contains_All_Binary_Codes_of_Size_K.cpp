#include <iostream>

using namespace std;

class Solution{
public:
    bool hasAllCodes(string s, int k){
        int s_size = s.size();
        int numOfSubstrings = 1 << k;
        if(s_size < k + numOfSubstrings - 1){
            return false;
        }

        int* doExist = new int[numOfSubstrings]{0};

        //fill "num" with the first (k - 1) bits
        int num = 0;
        string::iterator reader = s.begin();
        for(int i = 0; i < k - 1; i++){
            //push_back current bit
            num = (*reader == '1') ? (num << 1) + 1 : (num << 1);

            reader = reader + 1;
        }

        for(int i = 0; i < s_size - k + 1; i++){
            num = num % (numOfSubstrings / 2);

            //push_back current bit
            num = (*reader == '1') ? (num << 1) + 1 : (num << 1);
    
            doExist[num] = true;
            reader = reader + 1;
        }

        for(int i = 0; i < numOfSubstrings; i++){
            if(!doExist[i]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution* S = new Solution();

    cout << S->hasAllCodes("00110110", 2) << endl;

    return 0;
}