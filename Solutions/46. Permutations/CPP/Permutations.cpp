#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
private:
    int nums_size;
    vector<int> nums;
    vector<vector<int>> p;

public:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void permGenerator(int currentIdx) {
        if(currentIdx == nums_size) {
            p.push_back(nums);
            return;
        }

        for(int i = currentIdx; i < nums_size; ++i) {
            swap(nums[currentIdx], nums[i]);
            permGenerator(currentIdx + 1);
            swap(nums[currentIdx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        this->nums      = nums;
        this->nums_size = nums.size();
        permGenerator(0);
        return p;
    }
};

int main() {
    Solution S;

    //input
    vector<int> nums{1, 2, 4, 8};

    vector<vector<int>> result = S.permute(nums);

    cout << "number of permutations: " << result.size() << endl;
    for(auto i : result) {
        for(auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}
