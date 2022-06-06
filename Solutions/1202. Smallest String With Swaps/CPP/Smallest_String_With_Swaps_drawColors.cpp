#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution{
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs){
        int stringSize = s.size();
        vector<int> colorIndex(stringSize, -1);

        //grouping the swap pairs with colors
        for(int i = 0; i < pairs.size(); i++){
            int firstIndex  = pairs[i][0];
            int secondIndex = pairs[i][1];
            int firstColor  = colorIndex[firstIndex];
            int secondColor = colorIndex[secondIndex];
            if(firstColor == -1 and secondColor == -1){ //draw new color
                colorIndex[firstIndex] = i; //draw color i
                colorIndex[secondIndex] = i; //draw color i
            }
            else if(firstColor != -1 and secondColor == -1){ //draw secondIndex with firstIndex's color
                colorIndex[secondIndex] = firstColor;
            }
            else if(secondColor != -1 and firstColor == -1){ //draw firstIndex with secondIndex's color
                colorIndex[firstIndex] = secondColor;
            }
            else if(firstColor != -1 and secondColor != -1 and firstColor != secondColor){
                for(vector<int>::iterator iter = colorIndex.begin(); iter != colorIndex.end(); iter++){
                    if(*iter == secondColor){
                        *iter = firstColor;
                    }
                }
            }
        }

        map<int, vector<char>> charSets;
        for(int i = 0; i < colorIndex.size(); i++){
            if(colorIndex[i] != -1){
                charSets[colorIndex[i]].push_back(s[i]);
            }
        }
        for(map<int, vector<char>>::iterator iter = charSets.begin(); iter != charSets.end(); iter++){
            sort(iter->second.begin(), iter->second.end());
        }

        string newString = "";
        for(int i = 0; i < stringSize; i++){
            int index = colorIndex[i];
            if(index != -1){
                newString.push_back(*charSets[index].begin());
                charSets[index].erase(charSets[index].begin());
            }
            else{
                newString.push_back(s[i]);
            }
        }
        return newString;
    }
};

int main(){
    Solution* S = new Solution();

    //inputs
    string s = "gfedcbaaaa";
    vector<vector<int>> pairs{
        {0, 1},
        {3, 1},
        {0, 2},
        {5, 3},
        {4, 0}
    };

    cout << S->smallestStringWithSwaps(s, pairs) << endl;

    return 0;
}