#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    bool findNext(queue<int>& Q, vector<int>& visited) {
        if (!Q.empty()) {
            return true;
        }

        for (int i = 0; i < visited.size(); i++) {  // if Q is empty, assign the first non-visited node as group 1
            if (visited[i] == 0) {
                visited[i] = 1;  // group 1
                Q.push(i);
                return true;
            }
        }

        return false;  // all nodes are visited
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(), 0);  // 0: not visited, 1: group_1, 2: group_2

        queue<int> Q;
        while (findNext(Q, visited)) {
            // get next node
            int nodeID = Q.front();
            Q.pop();

            // change group from 1->2 or 2->1
            int group = visited[nodeID] % 2 + 1;
            for (vector<int>::iterator i = graph[nodeID].begin(); i != graph[nodeID].end(); i++) {
                if (visited[*i] == 0) {
                    visited[*i] = group;
                    Q.push(*i);
                }
                else if (visited[*i] != group) {  // group collision -> <-
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    Solution* S = new Solution();

    // input
    vector<vector<int>> graph{
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}};

    cout << S->isBipartite(graph) << endl;

    return 0;
}
