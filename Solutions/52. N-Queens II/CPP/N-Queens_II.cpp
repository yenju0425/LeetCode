#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int N; 
    int numOfSolutions;

public:
    void place(int l, int r, int v, int counter) {
        //check if N Queens are placed successfully
        if(counter == N) {
            numOfSolutions = numOfSolutions + 1;
            return;
        }
        
        //Try to place a Queen:
        //
        //    the binary representation of "l", "r", "v", and "availableCells" indicates the corresponding available cells
        //    e.g. n = 9, availableCells = 10111101
        //                                  ^    ^
        //                         Queen can be placed here
        //
        for(int i = 0; i < N; ++i) { //look for empty cells
            int newQueen = 1 << i;
            int availableCells = l | r | v; // left diagonal | right diagonal | vitercal line
            if((availableCells & newQueen) == 0) { //0: no collision; 1: collision
                //place (counter + 1) row
                place(((l | newQueen) >> 1), ((r | newQueen) << 1), (v | newQueen), counter + 1);
            }
        }
        return;
    }

    int totalNQueens(int n) {
        N = n;
        numOfSolutions = 0;
        place(0, 0, 0, 0);
        return numOfSolutions;
    }
};

int main() {
    Solution S;

    //input
    int n = 4;

    cout << S.totalNQueens(n) << endl;

    return 0;
}
