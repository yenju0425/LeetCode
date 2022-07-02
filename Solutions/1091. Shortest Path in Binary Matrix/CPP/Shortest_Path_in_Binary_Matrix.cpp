#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

class Solution{
private:
    int N;
    vector<vector<int>> dir;

public:
    int isValid(int m, int n){
        return m < N and m >= 0 and n < N and n >= 0;
    }

    int shortestPathBinaryMatrix(vector<vector<int>> &grid){
        if(grid[0][0] == 1){
            return -1;
        }

        this->N = grid.size();
        this->dir = vector<vector<int>>{{ 1,  1}, { 1,  0}, {1,  -1}, { 0,  1}, { 0, -1}, {-1,  1}, {-1,  0}, {-1, -1}};

        vector<queue<pair<int, int>>> Q(2);
        Q[0].push(pair<int, int>(0, 0));
        grid[0][0] = 1;

        int idx = 0;
        int stepCounter = 1;
        while(!Q[idx].empty()){
            while(!Q[idx].empty()){
                pair<int, int> pos = Q[idx].front();
                Q[idx].pop();

                int m = pos.first;
                int n = pos.second;

                if(m == N - 1 and n == N - 1){
                    return stepCounter;
                }

                for(int i = 0; i < 8; i++){
                    int m_ = m + dir[i][0];
                    int n_ = n + dir[i][1];
                    if(isValid(m_, n_) and grid[m_][n_] == 0){
                        Q[!idx].push(pair<int, int>(m_, n_));
                        grid[m_][n_] = 1;
                    }
                }
            }
            
            idx = !idx;
            stepCounter = stepCounter + 1;
        }
    
        return -1;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    vector<vector<int>> grid{
        {0, 0, 0},
        {1, 1, 0},
        {1, 1, 0}
    };

    cout << S->shortestPathBinaryMatrix(grid) << endl;

    return 0;
}