#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int minDistance(string word1, string word2){
        int word1_length = word1.length();
        int word2_length = word2.length();

        word1 = "$" + word1; //'$' is the "begin of string" char
        word2 = "$" + word2;

        vector<vector<int>> DP(word1_length + 1, vector<int>(word2_length + 1, 0));

        //init first col
        for(int i = 1; i <= word1_length; i++){
            DP[i][0] = i;
        }

        //init first row
        for(int i = 1; i <= word2_length; i++){
            DP[0][i] = i;
        }

        for(int i = 1; i <= word1_length; i++){
            for(int j = 1; j <= word2_length; j++){
                if(word1[i] != word2[j]){
                    DP[i][j] = min(DP[i - 1][j - 1], min(DP[i - 1][j], DP[i][j - 1])) + 1;
                }
                else{
                    DP[i][j] = DP[i - 1][j - 1];
                }
            }
        }

        return DP[word1_length][word2_length];
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    string word1 = "horse";
    string word2 = "ros";

    cout << S->minDistance(word1, word2) << endl;

    return 0;
}