#include <iostream>

using namespace std;

class Solution{
public:
    bool canConstruct(string s, int k){
        int charCount[26] = {0};

        int s_size = s.size();
        for(int i = 0; i < s_size; i++){
            int index = s[i] - 'a';
            charCount[index] = charCount[index] + 1;
        }

        int pair     = 0;
        int non_pair = 0;
        for(int i = 0; i < 26; i++){
            int parity = charCount[i] % 2;
            pair     = pair     + charCount[i] - parity;
            non_pair = non_pair + parity;
        }

        return (non_pair <= k and pair + non_pair >= k) ? true : false;
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    int k = 15;
    string s = "qlkzenwmmnpkopu";

    cout << S->canConstruct(s, k) << endl;

    return 0;
}