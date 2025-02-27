#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        int charCounter[26] = {0};
        for (string::iterator iter = s.begin(); iter != s.end(); iter++) {
            int idx          = *iter - 'a';
            charCounter[idx] = charCounter[idx] + 1;
        }

        map<int, int> freqCounter;
        for (int i = 0; i < 26; i++) {
            if (charCounter[i]) {
                if (!freqCounter.count(charCounter[i])) {
                    freqCounter[charCounter[i]] = 1;
                } else {
                    freqCounter[charCounter[i]] = freqCounter[charCounter[i]] + 1;
                }
            }
        }

        int numOfDeletions = 0;
        for (map<int, int>::iterator iter = freqCounter.begin(); iter != freqCounter.end(); iter++) {
            for (int i = 1; i < iter->second; i++) {
                for (int j = iter->first - 1; j >= 0; j--) {
                    numOfDeletions = numOfDeletions + 1;
                    if (!freqCounter.count(j) && j) {
                        freqCounter[j] = 1;
                        break;
                    }
                }
            }
        }

        return numOfDeletions;
    }
};

int main() {
    Solution S;

    // input
    string s = "aapple";

    cout << S.minDeletions(s) << endl;

    return 0;
}
