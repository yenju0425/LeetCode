#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int num1_length = num1.length();
        int num2_length = num2.length();

        string result = "";
        int temp      = 0;

        int result_length = num1_length + num2_length;
        for (int i = 0; i < result_length; ++i) {
            for (int j = 0; j <= i; ++j) {
                int n1 = (j < num1_length) ? num1[num1_length - 1 - j] - '0' : 0;
                int n2 = (i - j < num2_length) ? num2[num2_length - 1 - i + j] - '0' : 0;
                temp   = temp + n1 * n2;
            }

            char c = temp % 10 + '0';
            temp   = temp / 10;

            result.push_back(c);
        }

        // remove leading 0's
        while (result.back() == '0') {
            result.pop_back();
        }
        if (result.empty()) {
            result = "0";
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution S;

    string num1 = "99999";
    string num2 = "0";

    cout << S.multiply(num1, num2) << endl;

    return 0;
}
