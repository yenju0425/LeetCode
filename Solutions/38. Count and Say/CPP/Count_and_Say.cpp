#include <iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";

        for (int i = 1; i < n; ++i) {
            string temp = "";
            int counter = 0;
            for (string::iterator iter = result.begin(); iter != result.end(); ++iter) {
                counter = counter + 1;
                if ((iter + 1) == result.end() || *iter != *(iter + 1)) {
                    temp.append(to_string(counter));
                    temp.push_back(*iter);
                    counter = 0;
                }
            }
            result = temp;
        }

        return result;
    }
};

int main() {
    Solution S;

    // input
    int n = 7;

    cout << S.countAndSay(n) << endl;

    return 0;
}
