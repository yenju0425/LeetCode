#include <iostream>
#include <vector>
#include <tuple>
#include <map>

using namespace std;

class UnionFind{
private:
    map<string, tuple<string, double>> root; //find the root, and its ratio
    map<string, int> rank;

public:
    bool isValid(string x){
        return root.find(x) != root.end() ? true : false;
    }

    //get the root of a vertex (the root of the root must be itself)
    tuple<string, double> find(string x){
        if(!isValid(x)){
            root[x] = tuple<string, double>(x, 1);
            rank[x] = 1;
        }
        else if(get<0>(root[x]) != x){
            tuple<string, double> newPath = find(get<0>(root[x]));
            get<0>(root[x]) = get<0>(newPath);
            get<1>(root[x]) = get<1>(newPath) * get<1>(root[x]);
        }
        return root[x];
    }

    //perform the union of two components
    void unionSet(string x, string y, double r){ //x = y *ｒ
        tuple<string, double> rootX = find(x);
        tuple<string, double> rootY = find(y);
        if (get<0>(rootX) != get<0>(rootY)){
            if (rank[get<0>(rootX)] >= rank[get<0>(rootY)]){
                get<0>(root[get<0>(rootY)]) = get<0>(rootX); //y's new root is x's root
                get<1>(root[get<0>(rootY)]) = get<1>(rootX) / get<1>(rootY) * r;
                rank[get<0>(rootX)] += rank[get<0>(rootY)];
            }
            else{
                get<0>(root[get<0>(rootX)]) = get<0>(rootY); //x's new root is y's root
                get<1>(root[get<0>(rootX)]) = get<1>(rootY) / get<1>(rootX) / r;
                rank[get<0>(rootY)] += rank[get<0>(rootX)];
            }
        }
    }
};

class Solution{
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries){
        vector<double> results;
        UnionFind* UF = new UnionFind();

        //store data
        for(int i = 0; i < equations.size(); i++){
            UF->unionSet(equations[i][0], equations[i][1], values[i]);
        }

        //process queries
        for(int i = 0; i < queries.size(); i++){
            string var_0 = queries[i][0];
            string var_1 = queries[i][1];
            if(!UF->isValid(var_0) or !UF->isValid(var_1)){
                results.push_back(-1);
                continue;
            }
            tuple<string, double> root_0 = UF->find(var_0);
            tuple<string, double> root_1 = UF->find(var_1);
            if(get<0>(root_0) != get<0>(root_1)){
                results.push_back(-1);
                continue;
            }
            results.push_back(get<1>(root_1) / get<1>(root_0));
        }
        return results;
    }
};

int main(){
    vector<vector<string>> equations = {{"a", "b"}, {"d", "b"}, {"w", "x"}, {"z", "x"}, {"w", "d"}};
    vector<double> values = {2, 4, 5, 7, 8};
    vector<vector<string>> queries = {{"a", "z"}};

    Solution* S = new Solution();
    vector<double> ans = S->calcEquation(equations, values, queries);
    for(vector<double>::iterator i = ans.begin(); i != ans.end(); i++){
        cout << *i << ' ';
    }
    cout << endl;

    return 0;
}