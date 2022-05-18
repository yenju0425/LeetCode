#include <iostream>
#include <algorithm>

using namespace std;

class Solution{
public:
    string convertToTitle(int columnNumber){
        string result = "";
        while(columnNumber > 0){
            result.push_back(char((columnNumber - 1) % 26 + 65));
            columnNumber = (columnNumber - 1) / 26;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(){
    Solution* S = new Solution();

    cout << S->convertToTitle(28) << endl;
    
}