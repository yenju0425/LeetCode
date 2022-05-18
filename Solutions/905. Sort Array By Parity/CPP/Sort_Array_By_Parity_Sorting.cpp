#include <iostream>
#include <algorithm>  
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> sortArrayByParity(vector<int>& nums){
        sort(nums.begin(), nums.end(), [](int a, int b){
            if(a % 2 != b % 2){
                return bool(b % 2);
            }
            else{
                return a < b;
            }
        });
        return nums;
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