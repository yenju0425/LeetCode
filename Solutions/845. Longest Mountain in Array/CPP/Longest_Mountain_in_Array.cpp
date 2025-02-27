#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        arr.push_back(arr.back());

        int cur_state = 0;  //"0": non, "+": acc, "-": dec
        int nxt_state = 0;
        int max_len   = 0;
        int cur_len   = 0;

        int arr_size = arr.size();
        for (int i = 1; i < arr_size; i++) {
            nxt_state = arr[i] - arr[i - 1];
            if (cur_state == 0) {
                if (nxt_state > 0) {
                    cur_len   = 1;
                    cur_state = nxt_state;
                }
            } else if (cur_state > 0) {
                if (nxt_state != 0) {
                    cur_len = cur_len + 1;
                } else {
                    cur_len = 0;
                }
                cur_state = nxt_state;
            } else {
                if (nxt_state >= 0) {
                    max_len = max(max_len, cur_len + 1);
                    cur_len = (nxt_state > 0);
                } else {
                    cur_len = cur_len + 1;
                }
                cur_state = nxt_state;
            }
        }

        return max_len;
    }
};

int main() {
    Solution S;

    // input
    vector<int> M{0, 1, 2, 3, 4, 5, 4, 3, 2, 1, 0};

    cout << S.longestMountain(M) << endl;

    return 0;
}
