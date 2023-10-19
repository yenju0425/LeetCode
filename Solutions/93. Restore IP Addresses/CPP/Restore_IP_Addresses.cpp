#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<int> nums;
    vector<string> IPs;

public:
    void IPgenerator(string s, int n) {
        if (n == 0) {
            if (s == "") {
                string IP = to_string(nums[0]);
                for (int i = 1; i < 4; i++) {
                    IP.append('.' + to_string(nums[i]));
                }
                IPs.push_back(IP);
            }
            return;
        }

        for (int i = 1; i <= 3 and i <= s.size(); i++) {
            // check if the number is valid
            string num_str = s.substr(0, i);
            int num_int = stoi(num_str);
            if ((i > 1 and num_str[0] == '0') or num_int > 255) {
                continue;
            }

            nums.push_back(num_int);
            IPgenerator(s.substr(i), n - 1);
            nums.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        IPgenerator(s, 4);
        return IPs;
    }
};

int main() {
    Solution* S = new Solution();

    // input
    string s = "0000";

    vector<string> result = S->restoreIpAddresses(s);

    for (auto i : result) {
        cout << i << endl;
    }

    return 0;
}
