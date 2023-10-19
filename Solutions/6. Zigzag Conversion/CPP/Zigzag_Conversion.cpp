#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }

        vector<string> rowStrings(numRows, "");

        int s_size = s.size();
        for (int i = 0; i < s_size; ++i) {
            int magicNum = numRows - 1;
            int rowIndex = abs(magicNum - i % (2 * magicNum));
            rowStrings[rowIndex].push_back(s[i]);
        }

        string result = "";

        for (int i = numRows - 1; i >= 0; --i) {
            result = result + rowStrings[i];
        }

        return result;
    }
};

int main() {
    Solution S;

    // inputs
    string s = "PAYPALISHIRING";
    int numRows = 3;

    cout << S.convert(s, numRows);

    return 0;
}
