#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> numbers;
        for (int i = 0; i < n; ++i) {
            numbers.push_back('1' + i);
        }

        int fact[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        for (int i = 1; i < 10; ++i) {
            fact[i] = fact[i - 1] * i;
        }

        int p = 0;
        int r = k - 1;
        string result;
        for (int i = n - 1; i > 0; --i) {
            p = r / fact[i];
            r = r % fact[i];

            result.push_back(numbers[p]);
            numbers.erase(numbers.begin() + p);
        }

        result.push_back(numbers[0]);
        return result;
    }
};

int main() {
    Solution S;

    int n = 4;
    int k = 9;

    cout << S.getPermutation(n, k) << endl;

    return 0;
}
