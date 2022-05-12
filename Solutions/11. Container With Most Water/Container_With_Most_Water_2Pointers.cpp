//Reference: https://leetcode.com/problems/container-with-most-water/discuss/6089/Anyone-who-has-a-O(N)-algorithm/7268
#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxArea(vector<int>& height){
        int vectorSize = height.size();
        int currentMax = 0;

        int left  = 0;
        int right = vectorSize - 1;

        for(int i = 0; i < vectorSize - 1; i++){ //why ?
            int area = min(height[left], height[right]) * (right - left);
            currentMax = max(currentMax, area);

            if(height[left] < height[right]){
                left = left + 1;
            }
            else{
                right = right - 1;
            }
        }
        return currentMax;
    }
};

int main(){
    vector<int> vect;
    vect.push_back(1);
    vect.push_back(8);
    vect.push_back(6);
    vect.push_back(2);
    vect.push_back(5);
    vect.push_back(4);
    vect.push_back(8);
    vect.push_back(3);
    vect.push_back(7);

    Solution *S = new Solution();

    cout << S->maxArea(vect) << endl;

    return 0;
}