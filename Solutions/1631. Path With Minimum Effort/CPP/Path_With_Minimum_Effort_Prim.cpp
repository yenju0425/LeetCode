#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution{
private:
    int M;
    int N;

public:
    bool isValid(int m, int n){
        if(m < M and m >= 0 and n < N and n >= 0){
            return true;
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights){
        int maxEffort = -1;

        M = heights.size();
        N = heights[0].size();

        vector<vector<bool>> visited(M, vector<bool>(N, false));
        vector<vector<int>> effort(M, vector<int>(N, numeric_limits<int>::max()));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> findMin;

        effort[0][0] = 0;
        findMin.push(tuple<int, int, int>(0, 0, 0));

        while(!findMin.empty()){
            //use "findMin" to get nextPosition
            tuple<int, int, int> nextPosition = findMin.top();
            int e = get<0>(nextPosition);
            int m = get<1>(nextPosition);
            int n = get<2>(nextPosition);
            findMin.pop();

            //if heights[m][n] is visited, then do nothing
            if(visited[m][n]){
                continue;
            }
            //otherwise, visit heights[m][n]
            visited[m][n] = true;

            //update maxEffort
            maxEffort = max(maxEffort, e);
            if(m == M - 1 and n == N - 1){ //!!!SOLUTION FOUND!!!
                return maxEffort;
            }

            //update neighbors
            int m_neighbors[4] = {m - 1, m    , m + 1, m    };
            int n_neighbors[4] = {n    , n + 1, n    , n - 1};
            for(int i = 0; i < 4; i++){
                int m_ = m_neighbors[i];
                int n_ = n_neighbors[i];
                if(isValid(m_, n_) and !visited[m_][n_]){
                    int e_ = abs(heights[m][n] - heights[m_][n_]);
                    if(e_ < effort[m_][n_]){
                        effort[m_][n_] = e_;
                        findMin.push(tuple<int, int, int>(e_, m_, n_));
                    }
                }
            }
        }
        return maxEffort;
    }
};

int main(){
    Solution* S = new Solution();

    vector<vector<int>> Map{
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    cout << S->minimumEffortPath(Map) << endl;

    return 0;
}