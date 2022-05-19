#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution{
public:
    int manhattanDistance(vector<int> p1, vector<int> p2){
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points){
        int numOfPoints = points.size();
        vector<bool> visited(numOfPoints, false); //true if a node is visited
        vector<int> distance(numOfPoints); //the distance to MST

        //choose point 0 as root
        visited[0] = true;
        distance[0] = 0;
        for(int i = 1; i < numOfPoints; i++){
            distance[i] = manhattanDistance(points[0], points[i]);
        }

        int cost = 0;
        for(int i = 1; i < numOfPoints; i++){
            //find next node
            int minIndex = -1;
            for(int j = 0; j < numOfPoints; j++){
                if(visited[j] == false and (minIndex == -1 or distance[j] < distance[minIndex])){
                    minIndex = j;
                }
            }
            visited[minIndex] = true;
            cost = cost + distance[minIndex];

            //update the distance of the non-visited nodes
            for(int j = 0; j < numOfPoints; j++){
                if(visited[j] == false){
                    distance[j] = min(distance[j], manhattanDistance(points[minIndex], points[j]));
                }
            }
        }
        return cost;
    }
};

int main(){
    vector<vector<int>> points{
        {3, 12},
        {-2, 5},
        {-4, 1}
    };

    Solution* S = new Solution();

    cout << S->minCostConnectPoints(points);

    return 0;
}