#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum (vector<int> &nums, int target)
    {
        //a hash that store the indices
        unordered_map<int, int> nums_idx;

        int nums_size = nums.size();
        for (int i = 0; i < nums_size; i++)
        {
            if (nums_idx.find(target - nums[i]) != nums_idx.end())
            {
                return vector<int>{nums_idx[target - nums[i]], i};
            }
            else
            {
                nums_idx[nums[i]] = i;
            }
        }

        return vector<int>(2, 0);
    }
};

int main()
{
    Solution S;

    //inputs
    int target = 9;
    vector<int> nums{15, 7, 11, 2};

    vector<int> result = S.twoSum(nums, target);

    for (auto i : result)
    {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}