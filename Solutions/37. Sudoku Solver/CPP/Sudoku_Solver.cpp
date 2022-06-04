#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    vector<vector<vector<bool>>> findNum_row; //findNum_row[i][j] stores all the possible numbers that can be filled in "board"
    vector<vector<vector<bool>>> findNum_col;
    vector<vector<vector<bool>>> findNum_blk;

    int counter;
    bool stuck;

public:
    int blockId(int &i, int &j){
        return (i / 3) * 3 + (j / 3);
    }

    int indexInBlock(int &i, int &j){
        return (i % 3) * 3 + (j % 3);
    }

    bool isEnd(){
        return (counter == 81) ? true : false;
    }

    void updateFindNum(int row, int col, int num){ //claim that board[i][j] will be fill with "num"
        int blk = blockId(row, col);
        int idx = indexInBlock(row, col);

        fill(findNum_row[row][col].begin(), findNum_row[row][col].end(), 0); //the "col-th" position for other numbers in the "row-th" row is unavailable (each position can only be filled with one number)
        fill(findNum_col[col][row].begin(), findNum_col[col][row].end(), 0);
        fill(findNum_blk[blk][idx].begin(), findNum_blk[blk][idx].end(), 0);

        for(int k = 0; k < 9; k++){
            findNum_row[row][k][num] = false; //every position in the "row-th" row cannot be filled with "num" (each number can only be used once)
            findNum_col[col][k][num] = false;
            findNum_blk[blk][k][num] = false;
        }
    }

    void fillNum(int row, int col, int num, vector<vector<char>> &board){
        updateFindNum(row, col, num);
        if(board[row][col] == '.'){
            board[row][col] = num + '1';
            counter = counter + 1;
        }
    }

    void solveSudoku(vector<vector<char>> &board){
        //init findNum_row, findNum_col, findNum_blk
        findNum_row = vector<vector<vector<bool>>>(9, vector<vector<bool>>(9, vector<bool>(9, true)));
        findNum_col = vector<vector<vector<bool>>>(9, vector<vector<bool>>(9, vector<bool>(9, true)));
        findNum_blk = vector<vector<vector<bool>>>(9, vector<vector<bool>>(9, vector<bool>(9, true)));

        //init counter. If counter == 81, problem is solved!
        counter = 0;
        stuck   = true;

        //pre-load batch for the first update
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    counter = counter + 1;
                    updateFindNum(i, j, board[i][j] - '1');
                    stuck = false;
                }
            }
        }

        while(true){
            if(isEnd()){
                return;
            }
            if(stuck){ //iteratively guess an answer for the next empty cell
                for(int i = 0; i < 9; i++){
                    for(int j = 0; j < 9; j++){
                        for(int k = 0; k < 9; k++){
                            int blk = blockId(i, j);
                            int idx = indexInBlock(i, j);
                            if(findNum_row[i][j][k] and findNum_col[j][i][k] and findNum_blk[blk][idx][k]){
                                vector<vector<char>> board_clone = board;

                                // guess k is the answer for board[i][j]
                                board_clone[i][j] = k + '1';

                                Solution* S = new Solution();
                                S->solveSudoku(board_clone);

                                if(board_clone[0][0] != '!'){ //if the guess is correct
                                    board = board_clone;
                                    return;
                                }
                            }
                        }
                    }
                }

                board = vector<vector<char>>(9, vector<char>(9, '!')); //ERROR
                return;
            }

            //get ready to fill in numbers for the next round
            stuck = true;
            for(int i = 0; i < 9; i++){
                for(int j = 0; j < 9; j++){
                    //check by position: if board[i][j] can only be filled with k, than add (i, j, k) to batch
                    if(board[i][j] == '.'){
                        int blk = blockId(i, j);
                        int idx = indexInBlock(i, j);

                        //check whether k is the only number that can be filled in board[i][j]
                        int num = -1; //-1: null or collision
                        for(int k = 0; k < 9; k++){
                            if(findNum_row[i][j][k] and findNum_col[j][i][k] and findNum_blk[blk][idx][k]){
                                if(num == -1){
                                    num = k;
                                }
                                else{ //collision
                                    num = -1;
                                    break;
                                }
                            }
                        }

                        if(num >= 0){
                            fillNum(i, j, num, board);
                            stuck = false;
                        }
                    }

                    //note: In order to speed up, I combine "check by position" and "check by number" in the same loop. 'i', 'j', and 'k' have different meanings between these two parts 
                    //check by number: if j can only be filled in board[i][k], than add (i, k, j) to batch
                    int pos_row = -1; //-1: null; -2: collision
                    int pos_col = -1;
                    int pos_blk = -1;
                    for(int k = 0; k < 9; k++){
                        int row = -1;
                        int col = -1;
                        int blk = -1;
                        int idx = -1;

                        //check whether j can only be place in the "k-th" position in "i-th" row
                        row = i;
                        col = k;
                        blk = blockId(row, col);
                        idx = indexInBlock(row, col);
                        if(findNum_row[row][col][j] and findNum_col[col][row][j] and findNum_blk[blk][idx][j]){
                            if(pos_row == -1){
                                pos_row = k;
                            }
                            else if(pos_row >= 0){
                                pos_row = -2;
                            }
                        }

                        //check whether j can only be place in the "k-th" position in "i-th" col
                        row = k;
                        col = i;
                        blk = blockId(row, col);
                        idx = indexInBlock(row, col);
                        if(findNum_row[row][col][j] and findNum_col[col][row][j] and findNum_blk[blk][idx][j]){
                            if(pos_col == -1){
                                pos_col = k;
                            }
                            else if(pos_col >= 0){
                                pos_col = -2;
                            }
                        }
                        
                        //check whether j can only be place in the "k-th" position in "i-th" blk
                        row = (i / 3) * 3 + k / 3;
                        col = (i % 3) * 3 + k % 3;
                        blk = blockId(row, col);
                        idx = indexInBlock(row, col);
                        if(findNum_row[row][col][j] and findNum_col[col][row][j] and findNum_blk[blk][idx][j]){
                            if(pos_blk == -1){
                                pos_blk = k;
                            }
                            else if(pos_blk >= 0){
                                pos_blk = -2;
                            }
                        }
                    }

                    if(pos_row >= 0){ //if pos_row is the only position to place j in "i-th" row
                        fillNum(i, pos_row, j, board);
                    }

                    if(pos_col >= 0){ //if pos_col is the only position to place j in "i-th" col
                        fillNum(pos_col, i, j, board);
                    }

                    if(pos_blk >= 0){ //if pos_blk is the only position to place j in "i-th" blk
                        fillNum((i / 3) * 3 + pos_blk / 3, (i % 3) * 3 + pos_blk % 3, j, board);
                    }
                }
            }
        }
    }
};

int main(){
    Solution* S = new Solution();

    vector<vector<char>> board{
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    S->solveSudoku(board);

    for(auto i : board){
        for(auto j : i){
            cout << j << ' ';
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}