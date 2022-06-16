#include <iostream>

using namespace std;

class Solution{
public:
    int countSubstrings(string s){
        int stringCounter = 0;

        int s_size = s.size();
        for(float i = 0; i <= s_size - 1; i = i + 0.5){ //odd and even
            int l = i;       //magic
            int r = i + 0.5; //magic
            while(l >= 0 and r < s_size and s[l] == s[r]){
                stringCounter = stringCounter + 1;
                l = l - 1;
                r = r + 1;
            }
        }

        return stringCounter;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    string s = "abcaac";

    cout << S->countSubstrings(s) << endl;

    return 0;
}