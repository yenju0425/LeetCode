#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int numOfCards = cardPoints.size();

        // init sum
        int sum = 0;
        for (int i = numOfCards - k; i < numOfCards; i++) {
            sum = sum + cardPoints[i];
        }

        int maxSum = sum;
        for (int i = numOfCards - k, j = 0; i < numOfCards; i++, j++) {
            sum = sum - cardPoints[i] + cardPoints[j];
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};

int main() {
    Solution* S = new Solution();

    // inputs
    int k = 3;
    vector<int> cardPoints{1, 2, 3, 4, 5, 6, 1};

    cout << S->maxScore(cardPoints, k) << endl;

    return 0;
}
