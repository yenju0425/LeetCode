#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    int M;
    int N;
    vector<vector<char>> grid;
    vector<vector<int>> dir;

public:
    bool isValid(int m, int n){
        return m < M and m >= 0 and n < N and n >= 0 and (grid[m][n] == ' ' or grid[m][n] == 'v');
    }

    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls){
        this->M = m;
        this->N = n;
        this->grid = vector<vector<char>>(m, vector<char>(n, ' '));
        this->dir  = vector<vector<int>>{{ 1,  0}, { 0,  1}, {-1,  0}, { 0, -1}};

        int numOfGuards = guards.size();
        for(int i = 0; i < numOfGuards; i++){
            grid[guards[i][0]][guards[i][1]] = 'g';
        }

        int numOfWalls = walls.size();
        for(int i = 0; i < numOfWalls; i++){
            grid[walls[i][0]][walls[i][1]] = 'w';
        }

        int couter = m * n - numOfGuards - numOfWalls;
        for(int i = 0; i < numOfGuards; i++){
            for(int j = 0; j < 4; j++){
                int row = guards[i][0] + dir[j][0];
                int col = guards[i][1] + dir[j][1];
                while(isValid(row, col)){
                    if(grid[row][col] != 'v'){
                        grid[row][col] = 'v';
                        couter = couter - 1;
                    }
                    row = row + dir[j][0];
                    col = col + dir[j][1];
                }
            }
        }
    
        return couter;
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    int m = 4;
    int n = 6;
    vector<vector<int>> guards{{0, 0}, {1, 1}, {2, 3}};
    vector<vector<int>> walls{{0, 1}, {2, 2}, {1, 4}};

    cout << S->countUnguarded(m, n, guards, walls) << endl;

    return 0;
}