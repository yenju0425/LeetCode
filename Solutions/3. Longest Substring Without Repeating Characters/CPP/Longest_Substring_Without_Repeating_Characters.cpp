#include <iostream>

using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s){
        if(s.empty()){
            return 0;
        }

        int stringLength = s.length();
        int maxLength = 1; //maxLength must >= '1'

        int *a = new int[stringLength]; 
        for(int i = 0; i < stringLength; i++){
            a[i] = 1;
        }

        //DP
        bool merge;
        for(int i = 0; i < stringLength - 1; i++){
            int magicNumber = i + 1;
            merge = false;
            for(int j = 0; j < stringLength - magicNumber; j++){
                if(a[j] == magicNumber and a[j] == a[j+1] and s[j] != s[j+magicNumber]){
                    a[j]++;
                    merge = true;
                }
            }
            if(merge){
                maxLength++;
            }
            else{ //no merge happened
                break;
            }
        }
        return maxLength;
    }
};

int main(){
    Solution* S = new Solution();
    cout << S->lengthOfLongestSubstring("abcabcbb") << endl;
    return 0;
}