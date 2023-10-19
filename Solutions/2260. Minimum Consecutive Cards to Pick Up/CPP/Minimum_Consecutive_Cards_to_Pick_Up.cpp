#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int numOfCards = cards.size();
        int minDistance = INT_MAX;

        unordered_map<int, int> UM;  // e.g. UM[2] = 3 -> the last time seeing a "2" is at index "3"
        for (int i = 0; i < numOfCards; i++) {
            unordered_map<int, int>::iterator iter = UM.find(cards[i]);
            if (iter != UM.end()) {
                int distance = i - iter->second + 1;
                minDistance = min(minDistance, distance);
            }

            UM[cards[i]] = i;
        }

        return (minDistance == INT_MAX) ? -1 : minDistance;
    }
};

int main() {
    Solution* S = new Solution();

    vector<int> cards{3, 4, 5, 7, 99, 98, 3, 6, 1, 2, 1, 3};

    cout << S->minimumCardPickup(cards) << endl;

    return 0;
}
