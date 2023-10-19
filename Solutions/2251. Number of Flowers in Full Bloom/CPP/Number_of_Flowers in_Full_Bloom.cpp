#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        const int flowers_size = flowers.size();

        vector<int> start(flowers_size, 0);
        vector<int> end(flowers_size, 0);

        for (int i = 0; i < flowers_size; ++i) {
            start[i] = flowers[i][0];
            end[i] = flowers[i][1];
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        vector<int> result(people.size());
        transform(people.begin(), people.end(), result.begin(), [&](int n) {
            return (upper_bound(start.begin(), start.end(), n) - start.begin()) - (lower_bound(end.begin(), end.end(), n) - end.begin());
        });

        return result;
    }
};

int main() {
    Solution S;

    // input
    vector<vector<int>> flowers = {{1, 6}, {3, 7}, {9, 12}, {4, 13}};
    vector<int> people = {2, 3, 7, 11};

    vector<int> result = S.fullBloomFlowers(flowers, people);
    for (auto& i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
