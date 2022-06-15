#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> plusOne(vector<int> &digits){
        int digits_size = digits.size();
        for(int i = digits_size - 1; i >= 0; i--){
            if(digits[i] < 9){
                digits[i] = digits[i] + 1;
                return digits;
            }
            else{
                digits[i] = 0;
            }
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    vector<int> nums{9, 9, 9};

    vector<int> result = S->plusOne(nums);

    for(auto i : result){
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}