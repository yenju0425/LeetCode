#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class UnionFind{
private:
    vector<int> root;
    vector<int> rank;

public:
    UnionFind(int sz){
        root = vector<int>(sz);
        rank = vector<int>(sz);
        for (int i = 0; i < sz; i++){
            root[i] = i;
            rank[i] = 1;
        }
    }
    
    //Get the root of a vertex (the root of the root must be itself)
    int find(int x){
        if (root[x] != x){
            root[x] = find(root[x]);
        }

        return x;
    }

    //Perform the union of two components
    void unionSet(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY){
            if (rank[rootX] >= rank[rootY]){
                root[rootY] = rootX; //rootY's new boss is rootX
                rank[rootX] += rank[rootY];
            }
            else{
                root[rootX] = rootY; //rootX's new boss is rootY
                rank[rootY] += rank[rootX];
            }
        }
    }
};

class Solution{
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs){
        int stringLength = s.size();

        UnionFind* UF = new UnionFind(stringLength);
        for(int i = 0; i < pairs.size(); i++){
            UF->unionSet(pairs[i][0], pairs[i][1]);
        }

        unordered_map<int, vector<int>> Group; //put the chars with the same root together
        for(int i = 0; i < stringLength; i++){
            int root = UF->find(i);
            Group[root].push_back(i);
        }

        string newString(stringLength, ' ');
        for(unordered_map<int, vector<int>>::iterator i = Group.begin(); i != Group.end(); i++){
            vector<char> index2char;
            vector<int>  indices = i->second;
            for(int j = 0; j < indices.size(); j++){
                index2char.push_back(s[indices[j]]);
            }
            sort(index2char.begin(), index2char.end());

            for(int j = 0; j < indices.size(); j++){
                newString[indices[j]] = index2char[j];
            }
        }

        return newString;
    }
};

int main(){
    Solution* S = new Solution();

    //inputs
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