#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    string longestCommonPrefix(vector<string> &strs){
        string result = "";
        int counter = 0;
        while(counter < strs[0].size()){ //return if the first string is already empty
            for(int i = 1; i < strs.size(); i++){
                if(counter >= strs[i].size() or strs[i][counter] != strs[0][counter]){
                    return result;
                }
            }
            result.push_back(strs[0][counter]);
            counter = counter + 1;
        }
        return result;
    }
};

int main(){
    Solution* S = new Solution();

    //input
    vector<string> strs{"a", "abc", "apple"};

    cout << S->longestCommonPrefix(strs) << endl;
}