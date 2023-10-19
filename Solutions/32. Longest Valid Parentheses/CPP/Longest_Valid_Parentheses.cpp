#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int stack_size = 0;
        int max_size = 0;

        stack<vector<int>> S;
        S.push(vector<int>{0, 0});

        for (string::iterator i = s.begin(); i != s.end(); ++i) {
            if (*i == '(') {
                stack_size = stack_size + 1;
            }
            else {
                stack_size = stack_size - 1;

                if (stack_size < 0) {
                    stack_size = 0;
                    max_size = max(max_size, S.top()[1]);
                    S.pop();
                    S.push(vector<int>{0, 0});
                }
                else {
                    int count = 1;
                    while (!S.empty() && stack_size <= S.top()[0]) {
                        count = count + S.top()[1];
                        S.pop();
                    }
                    S.push(vector<int>{stack_size, count});
                }
            }
        }

        while (!S.empty()) {
            max_size = max(max_size, S.top()[1]);
            S.pop();
        }

        return max_size * 2;
    }
};

int main() {
    Solution S;

    // input
    string s = "(()";

    cout << S.longestValidParentheses(s) << endl;

    return 0;
}
