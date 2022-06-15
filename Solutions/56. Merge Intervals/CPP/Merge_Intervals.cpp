#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals){
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);

        int intervals_size = intervals.size();
        for(int i = 1; i < intervals_size; i++){
            if(intervals[i][0] <= result.back()[1]){
                result.back()[1] = max(intervals[i][1], result.back()[1]);
            }
            else{
                result.push_back(intervals[i]);
            }
        }
    
        return result;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    vector<vector<int>> v{
        {1, 4},
        {0, 2},
        {3, 5}
    };

    vector<vector<int>> result = S->merge(v);

    for(auto i : result){
        cout << i[0] << ' ' << i[1] << endl;
    }

    return 0;
}