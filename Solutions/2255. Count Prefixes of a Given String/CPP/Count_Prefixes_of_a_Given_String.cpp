#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int countPrefixes(vector<string> &words, string s){
        int counter = 0;
        for(int i = 0; i < words.size(); i++){
            bool match = true;
            for(int j = 0; j < words[i].size(); j++){
                if(j >= s.size() or words[i][j] != s[j]){
                    match = false;
                    break;
                }
            }
            if(match){
                counter++;
            }
        }
        return counter;
    }
};

int main(){
    vector<string> words{
        "aa",
        "aabd",
        "c"
    };

    string s = "aabdk";

    Solution* S = new Solution();

    cout << S->countPrefixes(words, s) << endl;

    return 0;
}