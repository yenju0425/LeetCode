#include <iostream>

using namespace std;

class Solution{
public:
    bool canConstruct(string s, int k){
        int s_size = s.size();
        int charCount[26] = {0};
        for(int i = 0; i < s_size; i++){
            int index = s[i] - 'a';
            charCount[index] = charCount[index] + 1;
        }

        int pair    = 0;
        int nonPair = 0;
        for(int i = 0; i < 26; i++){
            int parity = charCount[i] % 2;
            pair    = pair    + charCount[i] - parity;
            nonPair = nonPair + parity;
        }

        return (nonPair <= k and pair + nonPair >= k) ? true : false;
    }
};

int main(){
    Solution* S = new Solution();
    cout << S->canConstruct("qlkzenwmmnpkopu", 15) << endl;
    return 0;
}