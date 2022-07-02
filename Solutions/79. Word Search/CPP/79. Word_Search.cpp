#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    int M;
    int N;
    vector<vector<int>>  dir;
    vector<vector<char>> board;
    string word;

public:
    bool isValid(int m, int n){
        return m < M and m >= 0 and n < N and n >= 0;
    }

    bool DFS(int m, int n, int idx){
        if(idx >= word.size()){
            return true;
        }
        if(!isValid(m, n) or board[m][n] != word[idx]){
            return false;
        }
        
        bool result = false;
        for(int i = 0; i < 4 and !result; i++){
            board[m][n] = -board[m][n];
            result = DFS(m + dir[i][0], n + dir[i][1], idx + 1);
            board[m][n] = -board[m][n];
        }

        return result;
    }

    bool exist(vector<vector<char>> &board, string word){
        this->dir = vector<vector<int>>{{ 1,  0}, { 0,  1}, {-1,  0}, { 0, -1}};
        this->board = board;
        this->word  = word;
        this->M = board.size();
        this->N = board[0].size();
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(DFS(i, j, 0)){
                    return true;
                }
            }
        }

        return false;
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    string word = "ABCCED";
    vector<vector<char>> board{
        {'A', 'B', 'C', 'E'}, 
        {'S', 'F', 'C', 'S'}, 
        {'A', 'D', 'E', 'E'}
    };

    cout << S->exist(board, word);

    return 0;
}