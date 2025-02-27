#include <iostream>

using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int s_size          = s.length();
        int numOfSubstrings = 1 << k;

        // return false, if the string does not have enough length
        if (s_size < k + numOfSubstrings - 1) {
            return false;
        }

        // doExist[num] = true, if the corresponding binary code of "num" do exist
        // e.g. k = 3, doExist[3] will be set to "true", if "011" is witnessed
        bool* doExist = new bool[numOfSubstrings]{false};

        // fill "num" with the first (k - 1) bits
        int num                 = 0;
        string::iterator reader = s.begin();
        for (int i = 0; i < k - 1; i++) {
            // push_back current bit
            num = (*reader == '1') ? (num << 1) + 1 : (num << 1);

            reader = reader + 1;
        }

        // sliding window algorithm
        for (int i = 0; i < s_size - k + 1; i++) {
            // discard the left most bit
            num = num & (numOfSubstrings / 2 - 1);

            // push_back current bit
            num = (*reader == '1') ? (num << 1) + 1 : (num << 1);

            doExist[num] = true;
            reader       = reader + 1;
        }

        for (int i = 0; i < numOfSubstrings; i++) {
            if (!doExist[i]) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution S;

    int k    = 2;
    string s = "00110110";

    cout << S.hasAllCodes(s, k) << endl;

    return 0;
}
