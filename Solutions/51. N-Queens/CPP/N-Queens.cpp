#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    int N; 
    vector<vector<string>> placement;
    vector<string> temp_placement;

public:
    //convert the placing representation to string
    //e.g. n = 9, newQueen = 001000000,
    //convert(newQueen) --> "..Q......"
    //
    string int2string(int &newQueen){
        string newQueen_str;
        for(int i = 1 << (N - 1); i > 0; i = i >> 1){
            ((newQueen & i) != 0) ? newQueen_str.push_back('Q') : newQueen_str.push_back('.');
        }
        return newQueen_str;
    }
    
    //the binary representation of "availableCells" indicates its corresponding available cells
    //e.g. n = 9, availableCells = 10111101
    //                              ^    ^
    //                     Queen can be placed here
    //
    void place(int l, int r, int m, int counter){
        //check if N Queens are placed successfully
        if(counter == N){
            placement.push_back(temp_placement);
            return;
        }

        //try to place a Queen
        for(int i = 0; i < N; i++){
            int newQueen = 1 << i;
            int availableCells = l | r | m;
            if((availableCells & newQueen) == 0){ //0: no collision; 1: collision
                //place new Queen
                temp_placement.push_back(int2string(newQueen));

                //place next row
                place(((l | newQueen) >> 1), ((r | newQueen) << 1), (m | newQueen), counter + 1);

                //get ready for another trial
                temp_placement.pop_back();
            }
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n){
        N = n;
        place(0, 0, 0, 0);
        return placement;
    }
};

int main(){
    Solution* S = new Solution();

    int nums = 4;

    vector<vector<string>> result = S->solveNQueens(nums);

    for(auto i : result){
        for(auto j : i){
            cout << j << endl;
        }
        cout << endl;
    }

    return 0;
}