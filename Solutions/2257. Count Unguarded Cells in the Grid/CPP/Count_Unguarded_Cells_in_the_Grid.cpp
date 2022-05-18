#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    int M;
    int N;
    vector<vector<char>> map;

public:
    bool isValid(int m, int n){
        if(m < M and m >= 0 and n < N and n >= 0 and (map[m][n] == ' ' or map[m][n] == 'v')){
            return true;
        }
        return false;
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls){
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

    vector<vector<int>> guards{{0, 0}, {1, 1}, {2, 3}};

    vector<vector<int>> walls{{0, 1}, {2, 2}, {1, 4}};

    cout << S->countUnguarded(4, 6, guards, walls) << endl;

    return 0;
}