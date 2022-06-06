#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    vector<vector<char>> map;
    int M;
    int N;

public:
    bool isValid(int i, int j){
        if(i < M and i >= 0 and j < N and j >= 0 and (map[i][j] == ' ' or map[i][j] == 'v')){
            return true;
        }
        return false;
    }

    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls){
        M = m;
        N = n;
        map = vector<vector<char>>(m, vector<char>(n, ' '));

        for(int i = 0; i < guards.size(); i++){
            map[guards[i][0]][guards[i][1]] = 'g';
        }

        for(int i = 0; i < walls.size(); i++){
            map[walls[i][0]][walls[i][1]] = 'w';
        }

        int couter = 0;
        int dirR[4] = {-1,  0,  1,  0};
        int dirC[4] = { 0, -1,  0,  1};
        for(int i = 0; i < guards.size(); i++){
            for(int dir = 0; dir < 4; dir++){
                int offsetR = dirR[dir];
                int offsetC = dirC[dir];
                while(isValid(guards[i][0] + offsetR, guards[i][1] + offsetC)){
                    if(map[guards[i][0] + offsetR][guards[i][1] + offsetC] != 'v'){
                        map[guards[i][0] + offsetR][guards[i][1] + offsetC] = 'v';
                        couter++;
                    }
                    offsetR += dirR[dir];
                    offsetC += dirC[dir];
                }
            }
        }
    
        return m * n - couter - guards.size() - walls.size();
    }
};

int main(){
    Solution* S = new Solution();

    //inputs
    int m = 4;
    int n = 6;
    vector<vector<int>> guards{{0, 0}, {1, 1}, {2, 3}};
    vector<vector<int>> walls{{0, 1}, {2, 2}, {1, 4}};

    cout << S->countUnguarded(m, n, guards, walls) << endl;

    return 0;
}