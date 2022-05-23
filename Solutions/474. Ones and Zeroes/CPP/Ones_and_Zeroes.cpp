#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:

public:
    int findMaxForm(vector<string>& strs, int m, int n){
        int strs_Size = strs.size();
        vector<vector<int>> count01(strs_Size, vector<int>(2, 0));

        //scan through every string in "strs"
        for(int i = 0; i < strs_Size; i++){
            //cache the current string
            string s = strs[i];

            //count how many 0's and 1's
            vector<int> count(2, 0);

            int s_size = s.size();
            for(int j = 0; j < s_size; j++){
                int index = s[j] - '0';
                count[index] = count[index] + 1;
            }

            count01[i] = count;
        }
        
        //lookupTable[i][j][k]: 
        //    - i: when first i strings in strs is available
        //    - j: max number of 0
        //    - k: max number of 1
        vector<vector<vector<int>>> lookupTable = vector<vector<vector<int>>>(strs_Size + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        for(int i = 1; i <= strs_Size; i++){
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= n; k++){
                    int source_0 = j - count01[i - 1][0];
                    int source_1 = k - count01[i - 1][1];
                    if(source_0 >= 0 and source_1 >= 0){
                        lookupTable[i][j][k] = max(lookupTable[i - 1][j][k], lookupTable[i - 1][source_0][source_1] + 1);
                    }
                    else{
                        lookupTable[i][j][k] = lookupTable[i - 1][j][k];
                    }
                }
            }
        }

        return lookupTable[strs_Size][m][n];
    }
};

int main(){
    Solution* S = new Solution();

    vector<string> strs{"10","0001","111001","1","0"};

    cout << S->findMaxForm(strs, 5, 3) << endl;

    return 0;
}