#include <iostream>
#include <vector>

using namespace std;

class Finder {
private:
    vector<int> nums;
    int nums_size;
    int cur_ptr;
    int target;
    int fuel;

public:
    Finder(vector<int> nums, int target) {
        this->nums      = nums;
        this->nums_size = nums.size();
        this->cur_ptr   = 0;
        this->target    = target;
        this->fuel      = nums_size; //fill the finder with "nums_size" unit of fuel
    }

    int find() {
        if(nums[cur_ptr] == target) {
            return cur_ptr;
        }

        //attempt to find next position
        if(fuel == 0) { //can't move anymore...
            return -1;
        }

        //find next position, and it will cost you half of the current fuel
        int nxt_ptr = 0;
        int fuel_used = fuel - fuel / 2;
        if(nums[cur_ptr] < target) {
            nxt_ptr = (cur_ptr + fuel_used) % nums_size;
            cur_ptr = (nums[nxt_ptr] < nums[cur_ptr]) ? cur_ptr : nxt_ptr; //if it will go too far, then stay at the current position
        }
        else {
            nxt_ptr = (cur_ptr + nums_size - fuel_used) % nums_size;
            cur_ptr = (nums[nxt_ptr] > nums[cur_ptr]) ? cur_ptr : nxt_ptr; //if it will go too far, then stay at the current position
        }
        fuel = fuel / 2;
        return find();
    }
};

class Solution {
public:
    int search(vector<int>& nums, int target) {
        Finder F(nums, target);
        return F.find();
    }
};

int main() {
    Solution S;

    //inputs
    int target = 2;
    vector<int> nums{3, 4, 5, 6, 1, 2};

    cout << S.search(nums, target) << endl;

    return 0;
}
