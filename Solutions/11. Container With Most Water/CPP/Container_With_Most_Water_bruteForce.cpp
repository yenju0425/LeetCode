#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxArea(vector<int> &height){
        int vectorSize = height.size();
        int currentMax = 0;
        for(int i = 0; i < vectorSize - 1; i++){
            for(int j = i + 1; j < vectorSize; j++){
                int area = min(height[i], height[j]) * (j - i);
                currentMax = max(currentMax, area);
            }
        }
        return currentMax;
    }
};

int main(){
    vector<int> vect{1, 8, 6, 2, 5, 4, 8, 3, 7};

    Solution* S = new Solution();

    cout << S->maxArea(vect) << endl;

    return 0;
}