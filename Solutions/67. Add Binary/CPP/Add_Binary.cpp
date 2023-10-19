#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";

        bool carry = 0;
        int a_size = a.size();
        int b_size = b.size();
        for (int i = 0; i < a_size or i < b_size; i++) {
            bool ai = (i >= a_size) ? 0 : a[a_size - i - 1] == '1';
            bool bi = (i >= b_size) ? 0 : b[b_size - i - 1] == '1';

            bool a_xor_b = ai ^ bi;
            bool a_and_b = ai & bi;

            char sum = (a_xor_b ^ carry) + '0';
            result.push_back(sum);

            carry = a_and_b | (a_xor_b & carry);
        }
        if (carry) {
            result.push_back('1');
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    Solution* S = new Solution();

    // inputs
    string a = "010";
    string b = "1011";

    cout << S->addBinary(a, b) << endl;

    return 0;
}
