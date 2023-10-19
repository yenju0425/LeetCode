#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> PQ(amount.begin(), amount.end());

        int fst = PQ.top();
        PQ.pop();

        int snd = PQ.top();
        PQ.pop();

        int stepConter = 0;
        while (fst > 0 or snd > 0) {
            PQ.push(fst - 1);
            PQ.push(snd - 1);
            stepConter = stepConter + 1;

            fst = PQ.top();
            PQ.pop();

            snd = PQ.top();
            PQ.pop();
        }

        return stepConter;
    }
};

int main() {
    Solution* S = new Solution();

    // input
    vector<int> amount{4, 5, 4, 3};

    cout << S->fillCups(amount) << endl;

    return 0;
}
