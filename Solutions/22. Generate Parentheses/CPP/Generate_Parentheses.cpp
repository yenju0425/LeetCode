#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> result;

public:
    void parenthesisGenerater(int left, int right, int counter, string p) {
        if (left == 0 && right == 0) {
            result.push_back(p);
            return;
        }

        if (counter > 0 && right > 0) {
            // add right
            parenthesisGenerater(left, right - 1, counter - 1, p + string(")"));
        }

        if (left > 0) {
            // add left
            parenthesisGenerater(left - 1, right, counter + 1, p + string("("));
            ;
        }
    }

    vector<string> generateParenthesis(int n) {
        parenthesisGenerater(n, n, 0, "");
        return result;
    }
};

int main() {
    Solution S;

    // input
    int n = 3;

    vector<string> result = S.generateParenthesis(n);

    for (auto i : result) {
        cout << i << endl;
    }

    return 0;
}
