#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for (const char& c : s) {
            if (c == '(' || c == '[' || c == '{') {
                S.push(c);
            }
            else if (c == ')') {
                if (S.empty() || S.top() != '(') {
                    return false;
                }
                S.pop();
            }
            else if (c == ']') {
                if (S.empty() || S.top() != '[') {
                    return false;
                }
                S.pop();
            }
            else if (c == '}') {
                if (S.empty() || S.top() != '{') {
                    return false;
                }
                S.pop();
            }
            else {
                return false;
            }
        }

        if (!S.empty()) {
            return false;
        }

        return true;
    }
};

int main() {
    Solution S;

    // input
    string s = "()[]{}";

    cout << S.isValid(s) << endl;

    return 0;
}
