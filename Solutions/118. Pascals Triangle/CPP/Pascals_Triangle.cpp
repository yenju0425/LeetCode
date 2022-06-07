#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
    
        result.push_back(vector<int>{1});

        for(int i = 1; i < numRows; i++){
            vector<int> newRow(i + 1, 1);

            for(int j = 1; j < i; j++){
                newRow[j] = result[i - 1][j] + result[i - 1][j - 1];
            }
            
            result.push_back(newRow);
        }

        return result;
    }
};

int main(){
    Solution* S = new Solution();

    //input
    int numRows = 5;

    vector<vector<int>> result = S->generate(numRows);

    for(auto i : result){
        for(auto j : i){
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}