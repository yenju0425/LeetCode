#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> RomanNum{
        {'I', 'V', 'X'},
        {'X', 'L', 'C'},
        {'C', 'D', 'M'},
        {'M', '?', '?'}};

    vector<vector<int>> numRef{
        {},
        {0},
        {0, 0},
        {0, 0, 0},
        {0, 1},
        {1},
        {1, 0},
        {1, 0, 0},
        {1, 0, 0, 0},
        {0, 2}};

public:
    string digitToString(int d, int n) {
        string s = "";
        for (vector<int>::iterator i = numRef[d].begin(); i != numRef[d].end(); ++i) {
            s.push_back(RomanNum[n][*i]);
        }
        return s;
    }

    string intToRoman(int num) {
        string s = "";
        for (int i = 0; num != 0; ++i) {
            int digit = num % 10;
            num = num / 10;
            s = digitToString(digit, i) + s;
        }
        return s;
    }
};

int main() {
    Solution S;

    // input
    int num = 1987;

    cout << S.intToRoman(num) << endl;

    return 0;
}
