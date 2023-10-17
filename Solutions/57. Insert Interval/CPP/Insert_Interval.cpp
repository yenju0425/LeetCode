#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct get_lowerBound {
    bool operator()(const vector<int>& pair, const int& val) {
        return (pair[1] < val);
    }
    bool operator()(const int& val, const vector<int>& pair) {
        return (val < pair[1]);
    }
};

struct get_upperBound {
    bool operator()(const vector<int>& pair, const int& val) {
        return (pair[0] < val);
    }
    bool operator()(const int& val, const vector<int>& pair) {
        return (val < pair[0]);
    }
};

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty()) {
            return vector<vector<int>>{newInterval};
        }

        vector<vector<int>>::iterator lb = lower_bound(intervals.begin(), intervals.end(), newInterval[0], get_lowerBound());
        vector<vector<int>>::iterator ub = upper_bound(intervals.begin(), intervals.end(), newInterval[1], get_upperBound()) - 1;

        if(ub < lb) {
            intervals.insert(lb, newInterval);
        }
        else {
            (*ub)[0] = min((*lb)[0], newInterval[0]);
            (*ub)[1] = max((*ub)[1], newInterval[1]);
            intervals.erase(lb, ub);
        }

        return intervals;
    }
};

int main() {
    Solution S;

    //inputs
    vector<vector<int>> intervals{{1, 3}, {6, 9}};
    vector<int> newInterval{2, 5};

    vector<vector<int>> result = S.insert(intervals, newInterval);

    for(auto i : result) {
        for(auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}
