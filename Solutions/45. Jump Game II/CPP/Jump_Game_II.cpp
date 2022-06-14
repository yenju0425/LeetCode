#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int jump(vector<int> &nums){
        int stepCounter = 0;

        int mainFuelTank = 0;
        int auxiFuelTank = 0;
        
        int goal = nums.size() - 1;
        for(int i = 0; i < goal; i++){
            auxiFuelTank = max(auxiFuelTank, nums[i] - mainFuelTank);

            if(mainFuelTank == 0){
                mainFuelTank = auxiFuelTank;
                auxiFuelTank = 0;

                stepCounter  = stepCounter + 1;
            }

            //if the fuel is enough to reach the goal
            if(mainFuelTank >= goal - i){
                break;
            }

            mainFuelTank = mainFuelTank - 1;
        }

        return stepCounter;
    }
};

int main(){
    Solution* S = new Solution();

    //input
    vector<int> nums{2, 3, 1, 1, 4};

    cout << S->jump(nums) << endl;

    return 0;
}