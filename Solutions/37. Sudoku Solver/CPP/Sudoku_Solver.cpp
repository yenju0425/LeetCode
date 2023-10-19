#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int counter;
    bool stuck;
    vector<vector<vector<bool>>> availableNum_r;  // availableNum_r[i][j] stores all the available numbers that can be filled in "i-th" row's "j-th" position
    vector<vector<vector<bool>>> availableNum_c;  // availableNum_c[i][j] stores all the available numbers that can be filled in "i-th" col's "j-th" position
    vector<vector<vector<bool>>> availableNum_b;  // availableNum_b[i][j] stores all the available numbers that can be filled in "i-th" blk's "j-th" position

public:
    int blockId(int& i, int& j) {
        return (i / 3) * 3 + (j / 3);
    }

    int indexInBlock(int& i, int& j) {
        return (i % 3) * 3 + (j % 3);
    }

    bool isEnd() {
        return (counter == 81) ? true : false;
    }

    bool canFill(int row, int col, int num) {
        int blk = blockId(row, col);
        int idx = indexInBlock(row, col);
        return availableNum_r[row][col][num] && availableNum_c[col][row][num] && availableNum_b[blk][idx][num];
    }

    void updateAvailableNum(int row, int col, int num) {
        int blk = blockId(row, col);
        int idx = indexInBlock(row, col);

        fill(availableNum_r[row][col].begin(), availableNum_r[row][col].end(), false);  // the "col-th" position for other numbers in the "row-th" row is unavailable (each position can only be filled with one number)
        fill(availableNum_c[col][row].begin(), availableNum_c[col][row].end(), false);
        fill(availableNum_b[blk][idx].begin(), availableNum_b[blk][idx].end(), false);

        for (int k = 0; k < 9; ++k) {
            availableNum_r[row][k][num] = false;  // every position in the "row-th" row cannot be filled with "num" (each number can only be used once)
            availableNum_c[col][k][num] = false;
            availableNum_b[blk][k][num] = false;
        }
    }

    void fillNum(int row, int col, int num, vector<vector<char>>& board) {
        stuck = false;
        if (board[row][col] == '.') {
            board[row][col] = num + '1';
            counter = counter + 1;
            updateAvailableNum(row, col, num);
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        // init counter
        counter = 0;

        // init availableNum_r, availableNum_c, availableNum_b
        availableNum_r = vector<vector<vector<bool>>>(9, vector<vector<bool>>(9, vector<bool>(9, true)));
        availableNum_c = vector<vector<vector<bool>>>(9, vector<vector<bool>>(9, vector<bool>(9, true)));
        availableNum_b = vector<vector<vector<bool>>>(9, vector<vector<bool>>(9, vector<bool>(9, true)));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    counter = counter + 1;
                    updateAvailableNum(i, j, board[i][j] - '1');
                }
            }
        }

        while (!isEnd()) {
            // reset stuck
            stuck = true;
            for (int i = 0; i < 9; ++i) {
                for (int j = 0; j < 9; ++j) {
                    // check by position:
                    if (board[i][j] == '.') {
                        int num = -1;                  //-1: null or collision
                        for (int k = 0; k < 9; ++k) {  // check whether k is the only number that can be filled in board[i][j]
                            if (canFill(i, j, k)) {
                                if (num == -1) {
                                    num = k;
                                }
                                else {  // collision
                                    num = -1;
                                    break;
                                }
                            }
                        }

                        if (num >= 0) {
                            fillNum(i, j, num, board);
                        }
                    }

                    // note: In order to speed up, I combine "check by position" and "check by number" in the same loop. 'i', 'j', and 'k' have different meanings between these two parts
                    // check by number:
                    int pos_row = -1;  //-1: null; -2: collision
                    int pos_col = -1;
                    int pos_blk = -1;
                    for (int k = 0; k < 9; ++k) {
                        // check whether j can only be place in the "k-th" position in "i-th" row
                        if (canFill(i, k, j)) {
                            if (pos_row == -1) {
                                pos_row = k;
                            }
                            else if (pos_row >= 0) {
                                pos_row = -2;
                            }
                        }

                        // check whether j can only be place in the "k-th" position in "i-th" col
                        if (canFill(k, i, j)) {
                            if (pos_col == -1) {
                                pos_col = k;
                            }
                            else if (pos_col >= 0) {
                                pos_col = -2;
                            }
                        }

                        // check whether j can only be place in the "k-th" position in "i-th" blk
                        if (canFill((i / 3) * 3 + k / 3, (i % 3) * 3 + k % 3, j)) {
                            if (pos_blk == -1) {
                                pos_blk = k;
                            }
                            else if (pos_blk >= 0) {
                                pos_blk = -2;
                            }
                        }
                    }

                    if (pos_row >= 0) {  // if pos_row is the only position to place j in "i-th" row
                        fillNum(i, pos_row, j, board);
                    }

                    if (pos_col >= 0) {  // if pos_col is the only position to place j in "i-th" col
                        fillNum(pos_col, i, j, board);
                    }

                    if (pos_blk >= 0) {  // if pos_blk is the only position to place j in "i-th" blk
                        fillNum((i / 3) * 3 + pos_blk / 3, (i % 3) * 3 + pos_blk % 3, j, board);
                    }
                }
            }

            if (stuck) {  // iteratively guess an answer for the next empty cell
                for (int i = 0; i < 9; ++i) {
                    for (int j = 0; j < 9; ++j) {
                        for (int k = 0; k < 9; ++k) {
                            if (canFill(i, j, k)) {
                                vector<vector<char>> board_clone = board;

                                // guess k is the answer for board[i][j]
                                board_clone[i][j] = k + '1';

                                Solution S;
                                S.solveSudoku(board_clone);

                                if (board_clone[0][0] != '!') {  // if the guess is correct
                                    board = board_clone;
                                    return;
                                }
                            }
                        }
                    }
                }

                board[0][0] = '!';  // ERROR
                return;
            }
        }

        return;
    }
};

int main() {
    Solution S;

    // input
    vector<vector<char>> board{
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    S.solveSudoku(board);

    for (auto i : board) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
