#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    vector<vector<vector<bool>>> findNum_row; //findNum_row[i][j] stores all the possible numbers that can be filled in "board"
    vector<vector<vector<bool>>> findNum_col;
    vector<vector<vector<bool>>> findNum_blk;

public:
    int blockId(int &i, int &j){
        return (i / 3) * 3 + (j / 3);
    }

    int indexInBlock(int &i, int &j){
        return (i % 3) * 3 + (j % 3);
    }

    void updateFindNum(int row, int col, int num){
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

    void solveSudoku(vector<vector<char>> &board){
        //init findNum_row, findNum_col, findNum_blk
        findNum_row = vector<vector<vector<bool>>>(9, vector<vector<bool>>(9, vector<bool>(9, true)));
        findNum_col = vector<vector<vector<bool>>>(9, vector<vector<bool>>(9, vector<bool>(9, true)));
        findNum_blk = vector<vector<vector<bool>>>(9, vector<vector<bool>>(9, vector<bool>(9, true)));

        //if counter == 81, problem solved!
        int counter = 0;
        
        //pre-load batch for the first update
        vector<vector<int>> batch; //board[batch[i][0]][batch[i][1]] will be filled with batch[i][2] later
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    counter = counter + 1;
                    updateFindNum(i, j, board[i][j] - '1');
                    batch.push_back(vector<int>{i, j, board[i][j] - '1'});
                }
            }
        }

        while(true){
            //update findNum_row, findNum_col, findNum_blk, and the board
            if(counter == 81){
                return;
            }

            //if the batch is empty, iteratively guess an answer for the next empty cell
            if(batch.empty()){
                for(int i = 0; i < 9; i++){
                    for(int j = 0; j < 9; j++){
                        for(int k = 0; k < 9; k++){
                            int blk = blockId(i, j);
                            int idx = indexInBlock(i, j);
                            if(findNum_row[i][j][k] and findNum_col[j][i][k] and findNum_blk[blk][idx][k]){
                                vector<vector<char>> board_clone = board;

                                // guess k is the answer for board[i][j]
                                board_clone[i][j] = k + '1';

                                solveSudoku(board_clone);

                                if(board_clone[0][0] != '!'){ //if the guess is correct
                                    board = board_clone;
                                    return;
                                }
                            }
                        }
                    }
                }

                //"ERROR"
                board = vector<vector<char>>(9, vector<char>(9, '!'));
                return;
            }

            for(vector<vector<int>>::iterator iter = batch.begin(); iter != batch.end(); iter++){
                int row = (*iter)[0];
                int col = (*iter)[1];
                int num = (*iter)[2];

                if(board[row][col] == '.'){
                    board[row][col] = num + '1';
                    counter = counter + 1;
                }
            }

            //print
            for(auto i : board){
                for(auto j : i){
                    cout << j << ' ';
                }
                cout << endl;
            }
            cout << endl;

            batch.clear();

            //get ready to fill in numbers
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
                            updateFindNum(i, j, num);
                            batch.push_back(vector<int>{i, j, num});
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
                        updateFindNum(i, pos_row, j);
                        batch.push_back(vector<int>{i, pos_row, j});
                    }

                    if(pos_col >= 0){ //if pos_col is the only position to place j in "i-th" col
                        updateFindNum(pos_col, i, j);
                        batch.push_back(vector<int>{pos_col, i, j});
                    }

                    if(pos_blk >= 0){ //if pos_blk is the only position to place j in "i-th" blk
                        updateFindNum((i / 3) * 3 + pos_blk / 3, (i % 3) * 3 + pos_blk % 3, j);
                        batch.push_back(vector<int>{(i / 3) * 3 + pos_blk / 3, (i % 3) * 3 + pos_blk % 3, j});
                    }
                }
            }
        }
    }
};

int main(){
    Solution* S = new Solution();

    vector<vector<char>> board{
        {'.', '.', '.', '.', '.', '7', '.', '.', '9'}, 
        {'.', '4', '.', '.', '8', '1', '2', '.', '.'}, 
        {'.', '.', '.', '9', '.', '.', '.', '1', '.'}, 
        {'.', '.', '5', '3', '.', '.', '.', '7', '2'}, 
        {'2', '9', '3', '.', '.', '.', '.', '5', '.'}, 
        {'.', '.', '.', '.', '.', '5', '3', '.', '.'}, 
        {'8', '.', '.', '.', '2', '3', '.', '.', '.'}, 
        {'7', '.', '.', '.', '5', '.', '.', '4', '.'}, 
        {'5', '3', '1', '.', '7', '.', '.', '.', '.'}
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