#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int nums1_left = 0;
        int nums1_right = nums1.size();
        int nums2_left = 0;
        int nums2_right = nums2.size();
        while(1){
            int nums1_length = nums1_right - nums1_left;
            int nums2_length = nums2_right - nums2_left;
            if(nums1_length == 0){ //nums1 has 0
                int nums2MedianOffset = (nums2_length - 1) / 2;
                return double(nums2[nums2_left + nums2MedianOffset] + nums2[nums2_right - nums2MedianOffset - 1]) / 2;
            }
            else if(nums2_length == 0){ //nums2 has 0
                int nums1MedianOffset = (nums1_length - 1) / 2;
                return double(nums1[nums1_left + nums1MedianOffset] + nums1[nums1_right - nums1MedianOffset - 1]) / 2;
            }
            else if(nums1_length == 1 and nums2_length == 1){ //nums1, nums2 both have 1
                return double(nums1[nums1_left] + nums2[nums2_left]) / 2;
            }
            else if(nums1_length == 1){ //nums1 has 1, nums2 has even (2, 4, 6, ......)
                if(nums2_length % 2 == 0){
                    int n1 = nums1[nums1_left];                         //nums1Median
                    int n2 = nums2[(nums2_left + nums2_right) / 2 - 1]; //nums2MedianLeft
                    int n3 = nums2[(nums2_left + nums2_right) / 2];     //nums2MedianRight
                    return double(n1 + n2 + n3 - max(n1, n3) - min(n1, n2));
                }
                else{                   //nums1 has 1, nums2 has odd (3, 5, 7, ......)
                    int n1 = nums1[nums1_left];                         //nums1Median
                    int n2 = nums2[(nums2_left + nums2_right) / 2 - 1]; //nums2MedianLeft
                    int n3 = nums2[(nums2_left + nums2_right) / 2];     //nums2Median
                    int n4 = nums2[(nums2_left + nums2_right) / 2 + 1]; //nums2MedianRight
                    return double(n1 + n2 + n3 + n4 - max(n1, n4) - min(n1, n2)) / 2;
                }
            }
            else if(nums2_length == 1){ //nums2 has 1, nums1 has even (2, 4, 6, ......)
                if(nums1_length % 2 == 0){
                    int n1 = nums2[nums2_left];                         //nums2Median
                    int n2 = nums1[(nums1_left + nums1_right) / 2 - 1]; //nums1MedianLeft
                    int n3 = nums1[(nums1_left + nums1_right) / 2];     //nums1MedianRight
                    return double(n1 + n2 + n3 - max(n1, n3) - min(n1, n2));
                }
                else{                   //nums2 has 1, nums1 has odd (3, 5, 7, ......)
                    int n1 = nums2[nums2_left];                         //nums2Median
                    int n2 = nums1[(nums1_left + nums1_right) / 2 - 1]; //nums1MedianLeft
                    int n3 = nums1[(nums1_left + nums1_right) / 2];     //nums1Median
                    int n4 = nums1[(nums1_left + nums1_right) / 2 + 1]; //nums1MedianRight
                    return double(n1 + n2 + n3 + n4 - max(n1, n4) - min(n1, n2)) / 2;
                }
            }
            else if(nums1_length == 2 and nums2_length == 2){ //nums1, nums2 both have 2
                return double(max(nums1[nums1_left], nums2[nums2_left]) + min(nums1[nums1_right - 1], nums2[nums2_right - 1])) / 2; //It's magic......
            }
            else if(nums1_length == 2){ //nums1 has 2, nums2 has odd (3, 5, 7, ......)
                if(nums2_length % 2 == 1){
                    int nums2MedianLeft  = nums2[(nums2_left + nums2_right) / 2 - 1];
                    int nums2Median      = nums2[(nums2_left + nums2_right) / 2];
                    int nums2MedianRight = nums2[(nums2_left + nums2_right) / 2 + 1];
                    int n1 = min(nums1[nums1_right - 1], nums2MedianRight);
                    int n2 = max(nums1[nums1_left],      nums2MedianLeft);
                    int n3 = nums2Median;
                    return double(n1 + n2 + n3 - max(n1, max(n2, n3)) - min(n1, min(n2, n3)));
                }
                else{                   //nums1 has 2, nums2 has even (4, 6, 8, ......)
                    int nums2MedianLeft2  = nums2[(nums2_left + nums2_right) / 2 - 2];
                    int nums2MedianLeft1  = nums2[(nums2_left + nums2_right) / 2 - 1];
                    int nums2MedianRight1 = nums2[(nums2_left + nums2_right) / 2];
                    int nums2MedianRight2 = nums2[(nums2_left + nums2_right) / 2 + 1];
                    int n1 = min(nums1[nums1_right - 1], nums2MedianRight2);
                    int n2 = max(nums1[nums1_left],      nums2MedianLeft2);
                    int n3 = nums2MedianLeft1;
                    int n4 = nums2MedianRight1;
                    return double(n1 + n2 + n3 + n4 - max(max(n1, n2), max(n3, n4)) - min(min(n1, n2), min(n3, n4))) / 2;
                }
            }
            else if(nums2_length == 2){ //nums2 has 2, nums1 has odd (3, 5, 7, ......)
                if(nums1_length % 2 == 1){
                    int nums1MedianLeft  = nums1[(nums1_left + nums1_right) / 2 - 1];
                    int nums1Median      = nums1[(nums1_left + nums1_right) / 2];
                    int nums1MedianRight = nums1[(nums1_left + nums1_right) / 2 + 1];
                    int n1 = min(nums2[nums2_right - 1], nums1MedianRight);
                    int n2 = max(nums2[nums2_left],  nums1MedianLeft);
                    int n3 = nums1Median;
                    return double(n1 + n2 + n3 - max(n1, max(n2, n3)) - min(n1, min(n2, n3)));
                }
                else{                   //nums2 has 2, nums1 has even (4, 6, 8, ......)
                    int nums1MedianLeft2  = nums1[(nums1_left + nums1_right) / 2 - 2];
                    int nums1MedianLeft1  = nums1[(nums1_left + nums1_right) / 2 - 1];
                    int nums1MedianRight1 = nums1[(nums1_left + nums1_right) / 2];
                    int nums1MedianRight2 = nums1[(nums1_left + nums1_right) / 2 + 1];
                    int n1 = min(nums2[nums2_right - 1], nums1MedianRight2);
                    int n2 = max(nums2[nums2_left],  nums1MedianLeft2);
                    int n3 = nums1MedianLeft1;
                    int n4 = nums1MedianRight1;
                    return double(n1 + n2 + n3 + n4 - max(max(n1, n2), max(n3, n4)) - min(min(n1, n2), min(n3, n4))) / 2;
                }
            }
            else{ //nums1, nums2 have more than '2' (3, 4, 5, ......)
                int nums1MedianOffset = (nums1_length - 1) / 2; //It's magic......
                int nums2MedianOffset = (nums2_length - 1) / 2;
                double nums1Median = double(nums1[nums1_left + nums1MedianOffset] + nums1[nums1_right - nums1MedianOffset - 1]) / 2;
                double nums2Median = double(nums2[nums2_left + nums2MedianOffset] + nums2[nums2_right - nums2MedianOffset - 1]) / 2;
                if(nums1Median >= nums2Median){
                    if(nums1_length < nums2_length){ //nums1 is shorter
                        nums1_right = nums1_right - nums1MedianOffset;
                        nums2_left  = nums2_left  + nums1MedianOffset;
                    }
                    else{                            //nums2 is shorter
                        nums1_right = nums1_right - nums2MedianOffset;
                        nums2_left  = nums2_left  + nums2MedianOffset;
                    }
                }
                else{
                    if(nums1_length < nums2_length){ //nums1 is shorter
                        nums2_right = nums2_right - nums1MedianOffset;
                        nums1_left  = nums1_left  + nums1MedianOffset;
                    }
                    else{                            //nums2 is shorter
                        nums2_right = nums2_right - nums2MedianOffset;
                        nums1_left  = nums1_left  + nums2MedianOffset;
                    }
                }
            }
        }
    }
};

int main(){
    vector<int> a;
    a.push_back(1);
    a.push_back(3);

    vector<int> b;
    b.push_back(2);

    Solution *S = new Solution();

    cout << S->findMedianSortedArrays(a, b) << endl;

    return 0;
}