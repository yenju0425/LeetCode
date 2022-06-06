#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

class Solution{
public:
    int isValid(int r, int c, int n){
        if((r >= n or r < 0) or (c >= n or c < 0)){
            return false;
        }
        return true;
    }

    int shortestPathBinaryMatrix(vector<vector<int>> &grid){
        if(grid[0][0] == 1){
            return -1;
        }

        int sideLength = grid.size();
        vector<vector<bool>> isVisited(sideLength, vector<bool>(sideLength, false));

        int stepCounter = 1;

        vector<queue<pair<int, int>>> Q(2);
        int idx = 0;
        Q[idx].push(pair<int, int>(0, 0));
        isVisited[0][0] = true;
        while(!Q[idx].empty()){
            int _idx = (idx + 1) % 2;
            while(!Q[idx].empty()){
                pair<int, int> pos = Q[idx].front();
                Q[idx].pop();

                int posR = pos.first;
                int posC = pos.second;
                if(posR == sideLength - 1 and posC == sideLength - 1){
                    return stepCounter;
                }

                int row[8] = {posR - 1,  posR - 1,  posR - 1,  posR    ,  posR    ,  posR + 1,  posR + 1,  posR + 1};
                int col[8] = {posC - 1,  posC    ,  posC + 1,  posC - 1,  posC + 1,  posC - 1,  posC    ,  posC + 1};
                for(int i = 0; i < 8; i++){
                    int R = row[i];
                    int C = col[i];
                    if(isValid(R, C, sideLength) and !isVisited[R][C] and grid[R][C] == 0){
                        Q[_idx].push(pair<int, int>(R, C));
                        isVisited[R][C] = true;
                    }
                }
            }
            stepCounter = stepCounter + 1;
            idx = _idx;
        }
    
        return -1;
    }
};

int main(){
    Solution* S = new Solution();

    vector<vector<int>> grid{
        {1, 0, 0},
        {1, 1, 0},
        {1, 1, 1}
    };

    cout << S->shortestPathBinaryMatrix(grid) << endl;

    return 0;
}