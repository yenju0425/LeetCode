#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
private:
    int M;
    int N;
    vector<vector<int>> dir;

public:
    bool isValid(int m, int n) { return m < M && m >= 0 && n < N && n >= 0; }

    int minimumEffortPath(vector<vector<int>>& heights) {  // Dijkstra's Algorithm
        this->M   = heights.size();
        this->N   = heights[0].size();
        this->dir = vector<vector<int>>{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        vector<vector<int>> effort(M, vector<int>(N, INT_MAX));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        effort[0][0] = 0;
        pq.push(tuple<int, int, int>(0, 0, 0));

        while (!pq.empty()) {
            tuple<int, int, int> minimum = pq.top();
            int e                        = get<0>(minimum);
            int m                        = get<1>(minimum);
            int n                        = get<2>(minimum);
            pq.pop();

            if (m == M - 1 && n == N - 1) {
                return e;
            }

            // update neighbors
            for (int i = 0; i < 4; i++) {
                int m_ = m + dir[i][0];
                int n_ = n + dir[i][1];
                if (isValid(m_, n_)) {
                    int e_ = max(e, abs(heights[m][n] - heights[m_][n_]));
                    if (effort[m_][n_] > e_) {
                        effort[m_][n_] = e_;
                        pq.push(tuple<int, int, int>(e_, m_, n_));
                    }
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution S;

    // input
    vector<vector<int>> heights{{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

    cout << S.minimumEffortPath(heights) << endl;

    return 0;
}
