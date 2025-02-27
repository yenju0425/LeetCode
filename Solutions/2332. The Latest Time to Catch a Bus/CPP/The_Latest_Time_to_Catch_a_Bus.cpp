#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());

        vector<int>::iterator p = passengers.begin();  // p: the first passenger entering the upcomming bus
        for (vector<int>::iterator bus = buses.begin(); bus != buses.end() - 1; bus++) {
            p = min(p + capacity, upper_bound(p, passengers.end(), *bus));
        }

        // last bus
        vector<int>::iterator nxt_p = min(p + capacity, upper_bound(p, passengers.end(), buses.back()));
        if (nxt_p - p == capacity) {  // last bus is full
            p = nxt_p - 1;            // p: the last passenger
        } else {
            p = passengers.insert(nxt_p, buses.back() + 1);  // p: the last passenger (dummy)
        }

        for (vector<int>::iterator iter = p; iter != passengers.begin(); iter--) {
            if (*iter - 1 != *(iter - 1)) {
                return *iter - 1;
            }
        }

        return passengers.front() - 1;
    }
};

int main() {
    Solution S;

    int capacity = 1;
    vector<int> buses{3};
    vector<int> passengers{4};

    cout << S.latestTimeCatchTheBus(buses, passengers, capacity) << endl;

    return 0;
}
