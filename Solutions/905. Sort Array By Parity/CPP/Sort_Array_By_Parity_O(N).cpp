#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> sortArrayByParity(vector<int>& nums){
        vector<int> E;
        vector<int> O;
        for(vector<int>::iterator i = nums.begin(); i != nums.end(); i++){
            *i % 2 == 0 ? E.push_back(*i) : O.push_back(*i);
        }
        copy(O.begin(), O.end(), back_inserter(E));
        return E;
    }
};

int main(){
    Solution* S = new Solution();
    vector<int> v{3, 1, 2, 4};
    v = S->sortArrayByParity(v);

    for(auto i : v){
        cout << i << endl;
    }
    return 0;
}