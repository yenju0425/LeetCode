#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    vector<int> combanation;
    vector<vector<int>> combanations;

public:
    void generateCombanations(int n, int k){
        if(k == 0){
            combanations.push_back(combanation);
            return;
        }

        for(int i = k; i <= n; i++){
            combanation.push_back(i);
            generateCombanations(i - 1, k - 1);
            combanation.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k){
        generateCombanations(n, k);
        return combanations;
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    int n = 4;
    int k = 2;

    vector<vector<int>> result = S->combine(n, k);

    for(auto i : result){
        for(auto j : i){
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}