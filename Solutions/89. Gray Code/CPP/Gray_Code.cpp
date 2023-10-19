#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int num;
    vector<int> result;

public:
    void grayCodeGenerator(int n) {
        if (n < 0) {
            result.push_back(num);
            return;
        }

        grayCodeGenerator(n - 1);

        // flip the n-th bit
        num = num ^ (1 << n);

        grayCodeGenerator(n - 1);
    }

    vector<int> grayCode(int n) {
        num = 0;
        grayCodeGenerator(n - 1);
        return result;
    }
};

int main() {
    Solution* S = new Solution();

    // input
    int n = 3;

    vector<int> result = S->grayCode(n);

    for (auto i : result) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
