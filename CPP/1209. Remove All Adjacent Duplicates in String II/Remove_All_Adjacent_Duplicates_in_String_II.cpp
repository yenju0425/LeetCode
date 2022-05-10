#include <iostream>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int s_size = s.size();
        string newS = "";
        for(int i = 0; i < s_size; i++){
            newS.push_back(s[i]);
            bool isDuplicate = true;
            int newS_size = newS.size();
            for(int j = newS_size - 1; j > newS_size - k; j--){
                if(j <= 0 or newS[j - 1] != newS[j]){
                    isDuplicate = false;
                    break;
                }
            }
            if(isDuplicate){
                newS.erase(newS.size() - k);
            }
        }
        return newS;
    }
};

int main(){
    Solution* S = new Solution();

    cout << S->removeDuplicates("abcd", 2) << endl;
    return 0;
}