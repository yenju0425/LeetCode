#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        // init
        int s_size = s.size();
        vector<int> getGroupId(s_size, -1);

        // assign to groups
        int pairs_size = pairs.size();
        for (int i = 0; i < pairs_size; i++) {
            int index_a  = pairs[i][0];
            int index_b  = pairs[i][1];
            int& a_group = getGroupId[index_a];
            int& b_group = getGroupId[index_b];
            if (a_group == -1 && b_group == -1) {  // assign to new group i
                a_group = i;
                b_group = i;
            } else if (a_group != -1 && b_group == -1) {  // assign "index_b" to "a_group"
                b_group = a_group;
            } else if (a_group == -1 && b_group != -1) {  // assign "index_a" to "b_group"
                a_group = b_group;
            } else if (a_group != b_group) {
                int groupId = a_group;
                for (vector<int>::iterator iter = getGroupId.begin(); iter != getGroupId.end(); iter++) {
                    if (*iter == groupId) {
                        *iter = b_group;
                    }
                }
            }
        }

        // push the char to its corresponding vector
        unordered_map<int, vector<char>> groups;

        for (int i = 0; i < s_size; i++) {
            if (getGroupId[i] != -1) {
                groups[getGroupId[i]].push_back(s[i]);
            }
        }

        for (unordered_map<int, vector<char>>::iterator iter = groups.begin(); iter != groups.end(); iter++) {
            sort(iter->second.begin(), iter->second.end());
        }

        string result = s;
        for (int i = 0; i < s_size; i++) {
            int groupId = getGroupId[i];
            if (groupId != -1) {
                result[i] = groups[groupId].front();
                groups[groupId].erase(groups[groupId].begin());
            }
        }

        return result;
    }
};

int main() {
    Solution S;

    string s = "gfedcbaaaa";
    vector<vector<int>> pairs{{0, 1}, {3, 1}, {0, 2}, {5, 3}, {4, 0}};

    cout << S.smallestStringWithSwaps(s, pairs) << endl;

    return 0;
}
