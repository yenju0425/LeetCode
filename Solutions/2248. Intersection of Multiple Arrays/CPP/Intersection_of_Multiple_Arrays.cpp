#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<int> intersection(vector<vector<int>> &nums){
        vector<int> I;
        if(nums.empty()){
            return I;
        }

        for(vector<vector<int>>::iterator i = nums.begin(); i != nums.end(); i++){
            sort(i->begin(), i->end());
        }

        for(vector<int>::iterator i = nums[0].begin(); i != nums[0].end(); i++){
            bool found = true;
            for(vector<vector<int>>::iterator j = nums.begin(); j != nums.end(); j++){
                if(!binary_search(j->begin(), j->end(), *i)){
                    found = false;
                    break;
                }
            }
            if(found){
                I.push_back(*i);
            }
        }
        return I;
    }
};

int main(){
    Solution* S = new Solution();

    vector<vector<int>> sets{
        {1, 2, 3},
        {1, 3, 99},
        {1, 2, 78, 3}
    };

    vector<int> I = S->intersection(sets);

    for(vector<int>::iterator i = I.begin(); i != I.end(); i++){
        cout << *i << ' ';
    }
    cout << endl;

    return 0;
}