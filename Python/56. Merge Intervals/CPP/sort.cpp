#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals){
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){ // sort the 2D-vector using self-define cmp function
            return a[0] < b[0];
        });
        vector<vector<int>> mergedIntervals;
        mergedIntervals.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i = i + 1){
            if(intervals[i][0] <= mergedIntervals.back()[1]){
                mergedIntervals.back()[1] = max(intervals[i][1], mergedIntervals.back()[1]);
            }
            else{
                mergedIntervals.push_back(intervals[i]);
            }
        }
        return mergedIntervals;
    }
};

int main(){
    Solution *S = new Solution();
    vector<vector<int>> v {
        {1, 4},
        {0, 2},
        {3, 5}
    };

    vector<vector<int>> m = S->merge(v);
    for(int i = 0; i < m.size(); i++){
        cout << m[i][0] << ", " << m[i][1] << endl;
    }

    return 0;
}