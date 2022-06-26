#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2){
        int size = nums1.size();

        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0; i < size; i++){
            sum1 = sum1 + nums1[i];
            sum2 = sum2 + nums2[i];
        }

        vector<int> acc_diff(size + 1, 0);
        for(int i = 0; i < size; i++){
            acc_diff[i + 1] = nums1[i] - nums2[i] + acc_diff[i];
        }

        //look for swapping interval
        int maxDiff_2to1_start = INT_MIN;
        int maxDiff_2to1_final = INT_MIN;
        for(int i = 0; i < size; i++){
            maxDiff_2to1_start = max(maxDiff_2to1_start,                    + acc_diff[i]);
            maxDiff_2to1_final = max(maxDiff_2to1_final, maxDiff_2to1_start - acc_diff[i]);
        }

        //look for swapping interval
        int maxDiff_1to2_start = 0;
        int maxDiff_1to2_final = INT_MIN;
        for(int i = 0; i < size; i++){
            maxDiff_1to2_start = max(maxDiff_1to2_start,                    - acc_diff[i]);
            maxDiff_1to2_final = max(maxDiff_1to2_final, maxDiff_1to2_start + acc_diff[i]);
        }

        return max(sum1 + maxDiff_2to1_final, sum2 + maxDiff_1to2_final);
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    vector<int> nums1{28,34,38,14,30,31,23,7,28,3};
    vector<int> nums2{42,35,7,6,24,30,14,21,20,34};

    cout << S->maximumsSplicedArray(nums1, nums2) << endl;

    return 0;
}