#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int N;
    vector<vector<string>> placement;
    vector<string> temp_placement;

public:
    // Convert the placing representation to string:
    //
    //     e.g. n = 9, newQueen = 001000000,
    //     convert(newQueen) --> "..Q......"
    //
    string int2string(int& newQueen) {
        string newQueen_str;
        for (int i = 1 << (N - 1); i > 0; i = i >> 1) {
            ((newQueen & i) != 0) ? newQueen_str.push_back('Q') : newQueen_str.push_back('.');
        }
        return newQueen_str;
    }

    void place(int l, int r, int v, int counter) {
        // check if N Queens are placed successfully
        if (counter == N) {
            placement.push_back(temp_placement);
            return;
        }

        // Try to place a Queen:
        //
        //     the binary representation of "l", "r", "v", and "availableCells" indicates the corresponding available cells
        //     e.g. n = 9, availableCells = 10111101
        //                                   ^    ^
        //                          Queen can be placed here
        //
        for (int i = 0; i < N; ++i) {  // look for empty cells
            int newQueen = 1 << i;
            int availableCells = l | r | v;          // left diagonal | right diagonal | vitercal line
            if ((availableCells & newQueen) == 0) {  // 0: no collision; 1: collision
                // place new Queen
                temp_placement.push_back(int2string(newQueen));

                // place (counter + 1) row
                place(((l | newQueen) >> 1), ((r | newQueen) << 1), (v | newQueen), counter + 1);

                // get ready for another trial
                temp_placement.pop_back();
            }
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        N = n;
        place(0, 0, 0, 0);
        return placement;
    }
};

int main() {
    Solution S;

    // input
    int n = 4;

    vector<vector<string>> result = S.solveNQueens(n);

    for (auto i : result) {
        for (auto j : i) {
            cout << j << endl;
        }
        cout << endl;
    }

    return 0;
}
