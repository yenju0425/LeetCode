#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    vector<vector<vector<bool>>> availableNum_r; //availableNum_r[i][j] stores all the available numbers that can be filled in "i-th" row's "j-th" position
    vector<vector<vector<bool>>> availableNum_c; //availableNum_c[i][j] stores all the available numbers that can be filled in "i-th" col's "j-th" position
    vector<vector<vector<bool>>> availableNum_b; //availableNum_b[i][j] stores all the available numbers that can be filled in "i-th" blk's "j-th" position

public:
    int blockId(int &i, int &j){
        return (i / 3) * 3 + (j / 3);
    }

    int indexInBlock(int &i, int &j){
        return (i % 3) * 3 + (j % 3);
    }

    bool canFill(int row, int col, int num){
        int blk = blockId(row, col);
        int idx = indexInBlock(row, col);
        return availableNum_r[row][col][num] and availableNum_c[col][row][num] and availableNum_b[blk][idx][num];
    }

    void updateAvailableNum(int row, int col, int num){
        int blk = blockId(row, col);
        int idx = indexInBlock(row, col);

        fill(availableNum_r[row][col].begin(), availableNum_r[row][col].end(), false); //the "col-th" position for other numbers in the "row-th" row is unavailable (each position can only be filled with one number)
        fill(availableNum_c[col][row].begin(), availableNum_c[col][row].end(), false);
        fill(availableNum_b[blk][idx].begin(), availableNum_b[blk][idx].end(), false);

        for(int k = 0; k < 9; k++){
            availableNum_r[row][k][num] = false; //every position in the "row-th" row cannot be filled with "num" (each number can only be used once)
            availableNum_c[col][k][num] = false;
            availableNum_b[blk][k][num] = false;
        }
    }

    bool isValidSudoku(vector<vector<char>> &board){
        //init availableNum_r, availableNum_c, availableNum_b
        availableNum_r = vector<vector<vector<bool>>>(9, vector<vector<bool>>(9, vector<bool>(9, true)));
        availableNum_c = vector<vector<vector<bool>>>(9, vector<vector<bool>>(9, vector<bool>(9, true)));
        availableNum_b = vector<vector<vector<bool>>>(9, vector<vector<bool>>(9, vector<bool>(9, true)));

        //fill in the board one by one
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                //slip empty cells
                if(board[i][j] == '.'){
                    continue;
                }

                int num = (board[i][j] - '1');
                if(canFill(i, j, num)){
                    updateAvailableNum(i, j, num);
                }
                else{
                    return false;
                }
            }
        }
    
        return true;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    vector<vector<char>> board{
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'}, 
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, 
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, 
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, 
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, 
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, 
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, 
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, 
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    cout << S->isValidSudoku(board) << endl;

    return 0;
}