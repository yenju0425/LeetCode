#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum (vector<int> &nums, int target)
    {
        int nums_size = nums.size();

        vector<int> sortedNum = nums;
        sort(sortedNum.begin(), sortedNum.end());
        
        vector<int> result;

        int low  = 0;
        int high = nums_size - 1;
        while (low != high)
        {
            int sum = sortedNum[low] + sortedNum[high];
            if (sum > target)
            {
                high = high - 1;
            }
            else if (sum < target)
            {
                low = low + 1;
            }
            else
            { //solution found, get index
                for (int i = 0; i < nums_size; i++)
                {
                    if (nums[i] == sortedNum[low])
                    {
                        result.push_back(i);
                        break;
                    }
                }
                for (int i = nums_size - 1; i >= 0; i--)
                {
                    if (nums[i] == sortedNum[high])
                    {
                        result.push_back(i);
                        break;
                    }
                }
                break;
            }
        }
        return result;
    }
};

int main()
{
    Solution *S = new Solution();

    //inputs
    int target = 9;
    vector<int> nums{15, 7, 11, 2};

    vector<int> result = S->twoSum(nums, target);

    for (auto i : result)
    {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}