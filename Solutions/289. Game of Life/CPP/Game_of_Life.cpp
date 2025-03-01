#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> temp(m + 1, vector<int>(n + 1, 0));  // n + 1: dummy row and dummy column
        for (int i = 0; i < m; i = i + 1) {
            for (int j = 0; j < n; j = j + 1) {
                if (board[i][j] == 1) {
                    temp[(i + m) % (m + 1)][(j + n) % (n + 1)]     = temp[(i + m) % (m + 1)][(j + n) % (n + 1)] + 1;
                    temp[(i + m) % (m + 1)][j]                     = temp[(i + m) % (m + 1)][j] + 1;
                    temp[(i + m) % (m + 1)][(j + n + 2) % (n + 1)] = temp[(i + m) % (m + 1)][(j + n + 2) % (n + 1)] + 1;
                    temp[i][(j + n) % (n + 1)]                     = temp[i][(j + n) % (n + 1)] + 1;
                    temp[i][(j + n + 2) % (n + 1)]                 = temp[i][(j + n + 2) % (n + 1)] + 1;
                    temp[(i + m + 2) % (m + 1)][(j + n) % (n + 1)] = temp[(i + m + 2) % (m + 1)][(j + n) % (n + 1)] + 1;
                    temp[(i + m + 2) % (m + 1)][j]                 = temp[(i + m + 2) % (m + 1)][j] + 1;
                    temp[(i + m + 2) % (m + 1)][(j + n + 2) % (n + 1)] =
                        temp[(i + m + 2) % (m + 1)][(j + n + 2) % (n + 1)] + 1;
                }
            }
        }
        for (int i = 0; i < m; i = i + 1) {
            for (int j = 0; j < n; j = j + 1) {
                if (board[i][j] == 1 and (temp[i][j] < 2 or temp[i][j] > 3)) {
                    board[i][j] = 0;
                } else if (board[i][j] == 0 and temp[i][j] == 3) {
                    board[i][j] = 1;
                }
            }
        }
    }
};

int main() {
    Solution S;

    // input
    vector<vector<int>> board{
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0},
    };

    S.gameOfLife(board);

    for (auto i : board) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}
