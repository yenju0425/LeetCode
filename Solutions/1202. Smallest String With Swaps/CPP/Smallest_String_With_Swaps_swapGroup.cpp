#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class UnionFind {
private:
    vector<int> root;
    vector<int> rank;

public:
    UnionFind(int sz) {
        root = vector<int>(sz);
        rank = vector<int>(sz, 1);
        for (int i = 0; i < sz; i++) {
            root[i] = i;
        }
    }

    // Get the root of a vertex (the root of the root must be itself)
    int find(int x) {
        if (root[x] != x) {
            root[x] = find(root[x]);
        }

        return root[x];
    }

    // Perform the union of two components
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] >= rank[rootY]) {
                root[rootY] = rootX;
                rank[rootX] = rank[rootX] + rank[rootY];
            }
            else {
                root[rootX] = rootY;
                rank[rootY] = rank[rootY] + rank[rootX];
            }
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int s_size = s.size();
        int pairs_size = pairs.size();

        UnionFind* UF = new UnionFind(s_size);
        for (int i = 0; i < pairs_size; i++) {
            UF->unionSet(pairs[i][0], pairs[i][1]);
        }

        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < s_size; i++) {
            int root = UF->find(i);
            groups[root].push_back(i);
        }

        string result = s;
        for (unordered_map<int, vector<int>>::iterator i = groups.begin(); i != groups.end(); i++) {
            int group_size = i->second.size();
            if (group_size == 1) {
                continue;
            }

            vector<char> chars(group_size);
            vector<int> indices = i->second;

            // gather chars of the same group
            for (int j = 0; j < group_size; j++) {
                chars[j] = s[indices[j]];
            }

            sort(chars.begin(), chars.end());

            // update s
            for (int j = 0; j < group_size; j++) {
                result[indices[j]] = chars[j];
            }
        }

        return result;
    }
};

int main() {
    Solution* S = new Solution();

    // inputs
    string s = "gfedcbaaaa";
    vector<vector<int>> pairs{
        {0, 1},
        {3, 1},
        {0, 2},
        {5, 3},
        {4, 0}
    };

    cout << S->smallestStringWithSwaps(s, pairs) << endl;

    return 0;
}
