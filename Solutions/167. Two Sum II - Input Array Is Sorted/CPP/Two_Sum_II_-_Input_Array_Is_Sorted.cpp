#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int numbers_size = numbers.size();

        int left  = 0;
        int right = numbers_size - 1;

        while (left < right) {
            if (numbers[left] + numbers[right] < target) {
                left = left + 1;
            } else if (numbers[left] + numbers[right] > target) {
                right = right - 1;
            } else {
                break;
            }
        }

        vector<int> result = {left + 1, right + 1};  // 1-indexed array
        return result;
    }
};

int main() {
    Solution S;

    int target = 9;
    vector<int> numbers{2, 7, 11, 15};

    vector<int> result = S.twoSum(numbers, target);

    for (auto i : result) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}
