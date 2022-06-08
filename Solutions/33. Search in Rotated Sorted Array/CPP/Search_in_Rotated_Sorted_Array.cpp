#include <iostream>
#include <vector>

using namespace std;

class Finder{
private:
    vector<int> nums;
    int nums_size;
    int target;
    int fuel;

public:
    Finder(vector<int> nums, int target){
        this->nums      = nums;
        this->nums_size = nums.size();
        this->target    = target;
        this->fuel      = nums_size; //fill the finder with "nums_size" unit of fuel
    }

    int find(int position){
        if(nums[position] == target){
            return position;
        }

        //attempt to find next position
        if(fuel == 0){ //can't move anymore...
            return -1;
        }

        //find next position, and it will cost you half of the current fuel
        int next_position = 0;
        int fuel_used = (fuel == 1) ? fuel : fuel / 2; //O(logN)
        if(nums[position] < target){
            next_position = (position + fuel_used) % nums_size;
            if(nums[next_position] < nums[position]){ //if we will go too far
                next_position = position; //then stay at the current position
            }
        }
        else{
            next_position = (position + nums_size - fuel_used) % nums_size;
            if(nums[next_position] > nums[position]){
                next_position = position;
            }
        }
        fuel = fuel - fuel_used;
        return find(next_position);
    }
};

class Solution{
public:
    int search(vector<int>& nums, int target){
        Finder* F = new Finder(nums, target);
        return F->find(0);
    }
};

int main(){
    Solution* S = new Solution();

    //inputs
    int target = 2;
    vector<int> nums{3, 4, 5, 6, 1, 2}; //view "nums" as a circular array

    cout << S->search(nums, target) << endl;

    return 0;
}