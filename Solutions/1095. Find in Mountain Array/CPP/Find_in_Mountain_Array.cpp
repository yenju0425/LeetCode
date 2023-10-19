#include <iostream>
#include <vector>

using namespace std;

class MountainArray {
public:
    MountainArray(vector<int>& vec) {
        mountainArray = vec;
    }

    int get(int index) {
        return mountainArray[index];
    }

    int length() {
        return mountainArray.size();
    }

private:
    vector<int> mountainArray;
};

class Solution {
public:
    int binarySearch(const int& target, MountainArray& mountainArr, int begin, int end) {
        if (begin == end) {
            return -1;  // search failed
        }

        int partition = (begin + end) / 2;
        int height1 = mountainArr.get(partition);
        int height2 = (partition + 1 >= mountainArr.length()) ? -1 : mountainArr.get(partition + 1);
        bool accending = (height2 - height1) > 0;

        if (height1 < target) {
            if (accending) {
                return binarySearch(target, mountainArr, partition + 1, end);
            }
            else {
                return binarySearch(target, mountainArr, begin, partition);
            }
        }
        else if (height1 > target) {
            if (accending) {
                return binarySearch(target, mountainArr, begin, partition);
            }
            else {
                return binarySearch(target, mountainArr, partition + 1, end);
            }
        }

        return partition;
    }

    int mountainSearch(const int& target, MountainArray& mountainArr, int begin, int end) {
        if (begin == end) {
            return -1;  // search failed
        }

        int partition = (begin + end) / 2;
        int height1 = mountainArr.get(partition);
        int height2 = (partition + 1 >= mountainArr.length()) ? -1 : mountainArr.get(partition + 1);
        bool accending = (height2 - height1) > 0;

        if (height1 < target) {
            if (accending) {
                return mountainSearch(target, mountainArr, partition + 1, end);
            }
            else {
                return mountainSearch(target, mountainArr, begin, partition);
            }
        }
        else if (height1 > target) {
            if (accending) {
                int l = binarySearch(target, mountainArr, begin, partition);
                return (l >= 0) ? l : mountainSearch(target, mountainArr, partition + 1, end);
            }
            else {
                int l = mountainSearch(target, mountainArr, begin, partition);
                return (l >= 0) ? l : binarySearch(target, mountainArr, partition + 1, end);
            }
        }
        else {
            if (accending) {
                int l = binarySearch(target, mountainArr, begin, partition);
                return (l >= 0) ? l : partition;
            }
            else {
                int l = mountainSearch(target, mountainArr, begin, partition);
                return (l >= 0) ? l : partition;
            }
        }
    }

    int findInMountainArray(int target, MountainArray& mountainArr) {
        return mountainSearch(target, mountainArr, 0, mountainArr.length());
    }
};

int main() {
    Solution S;

    // input
    vector<int> vec = {1, 2, 3, 4, 5, 3, 1};
    MountainArray M(vec);

    int target = 3;

    cout << S.findInMountainArray(target, M) << endl;

    return 0;
}
