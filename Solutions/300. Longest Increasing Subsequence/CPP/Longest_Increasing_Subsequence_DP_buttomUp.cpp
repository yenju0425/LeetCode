#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> LISLengths;

public:
    int lengthOfLIS(vector<int>& nums) {
        LISLengths = vector<int>(nums.size(), 1);

        int maxLength = 1;
        for(int i = nums.size() - 2; i >= 0; --i) {
            for(int j = i + 1; j < nums.size(); ++j) {
                if(nums[i] < nums[j]){
                    LISLengths[i] = max(LISLengths[i], LISLengths[j] + 1);
                }
            }
            
            maxLength = max(maxLength, LISLengths[i]);
        }

        return maxLength;
    }
};

int main(){
    Solution S;

    //input
    vector<int> seq{0, 8, 4, 18, 16, 7, 15, 20, 17, 6, 14, 1, 9, 5, 13, 3, 11, 12, 2, 10, 19};

    cout << S.lengthOfLIS(seq) << endl;

    return 0;
}
