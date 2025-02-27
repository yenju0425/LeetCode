#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") {
            return 0;
        }

        int index  = -1;
        int h_size = haystack.size();
        int n_size = needle.size();
        for (int i = 0; i < h_size - n_size + 1; ++i) {
            bool same = true;
            for (int j = 0; j < n_size; ++j) {
                same = (haystack[i + j] == needle[j]);
                if (!same) {
                    break;
                }
            }
            if (same) {
                return i;
            }
        }

        return index;
    }
};

int main() {
    Solution S;

    string haystack = "hello";
    string needle   = "ell";

    cout << S.strStr(haystack, needle) << endl;

    return 0;
}
