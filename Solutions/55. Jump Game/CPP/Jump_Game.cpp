#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    bool canJump(vector<int> &nums){
        bool result = true;

        int mainFuelTank = 0;
        int auxiFuelTank = 0;

        int goal = nums.size() - 1;
        for(int i = 0; i < goal; i++){
            auxiFuelTank = max(auxiFuelTank, nums[i] - mainFuelTank);

            //refill mainFuelTank
            if(mainFuelTank == 0){
                if(auxiFuelTank == 0){
                    result = false;
                    break;
                }
                mainFuelTank = auxiFuelTank;
                auxiFuelTank = 0;
            }

            //if the fuel is enough to reach the goal
            if(mainFuelTank >= goal - i){
                break;
            }

            mainFuelTank = mainFuelTank - 1;
        }

        return result;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    vector<int> nums{2, 3, 1, 1, 4};

    cout << S->canJump(nums) << endl;

    return 0;
}