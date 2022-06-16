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
    //utility
    bool isValid(int m, int n){
        if(m < M and m >= 0 and n < N and n >= 0){
            return true;
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>> &heights){
        int maxEffortTaken = -1;

        M = heights.size();
        N = heights[0].size();

        vector<vector<int>> effort(M, vector<int>(N, numeric_limits<int>::max()));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> findMin;

        effort[0][0] = 0;
        findMin.push(tuple<int, int, int>(0, 0, 0));

        while(!findMin.empty()){
            //use "findMin" to get next position
            tuple<int, int, int> minimum = findMin.top();
            int e = get<0>(minimum);
            int m = get<1>(minimum);
            int n = get<2>(minimum);
            findMin.pop();

            //go to heights[m][n]
            if(m == M - 1 and n == N - 1){
                return e;
            }

            //update neighbors
            int m_adj[4] = {m - 1, m    , m + 1, m    };
            int n_adj[4] = {n    , n + 1, n    , n - 1};
            for(int index = 0; index < 4; index++){
                int m_ = m_adj[index];
                int n_ = n_adj[index];
                if(isValid(m_, n_)){
                    int e_ = max(e, abs(heights[m][n] - heights[m_][n_]));
                    if(effort[m_][n_] > e_){
                        effort[m_][n_] = e_;
                        findMin.push(tuple<int, int, int>(e_, m_, n_));
                    }
                }
            }
        }

        return -1;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    vector<vector<int>> Map{
        {1, 2, 2},
        {3, 8, 2},
        {5, 3, 5}
    };

    cout << S->minimumEffortPath(Map) << endl;

    return 0;
}