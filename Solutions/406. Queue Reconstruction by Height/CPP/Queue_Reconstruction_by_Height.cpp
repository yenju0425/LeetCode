#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b){
    return (a[0] == b[0]) ? a[1] < b[1] : a[0] > b[0];
}

class Solution{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people){
        vector<vector<int>> result;

        sort(people.begin(), people.end(), cmp);

        int numOfPeople = people.size();
        for(int i = 0; i < numOfPeople; i++){
            result.insert(result.begin() + people[i][1], people[i]);
        }

        return result;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    vector<vector<int>> people{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};

    vector<vector<int>> result = S->reconstructQueue(people);

    for(auto i : result){
        for(auto j : i){
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}