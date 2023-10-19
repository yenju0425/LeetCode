#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> PQ(target.begin(), target.end());

        unsigned int sum = 0;
        for (vector<int>::iterator iter = target.begin(); iter != target.end(); iter++) {
            sum = sum + *iter;
        }

        while (PQ.top() != 1) {
            int maxVal = PQ.top();

            // pop
            PQ.pop();
            sum = sum - maxVal;

            // check maxVal, sum
            if (sum > maxVal || sum == 0) {  // stuck, but PQ.top() != 1
                return false;
            }

            maxVal = maxVal % sum;

            // push
            sum = sum + maxVal;
            PQ.push(maxVal ? maxVal : sum);
        }

        return true;
    }
};

int main() {
    Solution* S = new Solution();

    // input
    vector<int> target{8, 5};

    cout << S->isPossible(target) << endl;

    return 0;
}
