#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Vertex{
private:
    map<int, int> adjList = {};

public:
    map<int, int> getAdjList(){
        return adjList;
    }

    void addEdge(int v, int t){
        adjList[v] = t;
    }
};

class Solution{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k){
        map<int, Vertex*> vertices;
        map<int, int> minTimes;

        //build graph
        for(vector<vector<int>>::iterator i = times.begin(); i != times.end(); i++){
            int v1 = (*i)[0];
            int v2 = (*i)[1];
            int t  = (*i)[2];

            if(vertices[v1] == nullptr){
                vertices[v1] = new Vertex();
                minTimes[v1] = numeric_limits<int>::max();
            }
            if(vertices[v2] == nullptr){
                vertices[v2] = new Vertex();
                minTimes[v2] = numeric_limits<int>::max();
            }
            vertices[v1]->addEdge(v2, t);
        }

        //Dijkstra Algorithm
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> findMin; //findMin->first: time needed; findMin->second: go to where
        findMin.push(vector<int>{0, k});

        while(!findMin.empty()){
            int nextT = findMin.top()[0];
            int nextV = findMin.top()[1];
            minTimes[nextV] = nextT;
            findMin.pop();

            if(nextV == n){ //target found
                return nextT;
            }

            //update neighbors
            map<int, int> neighbors = vertices[nextV]->getAdjList();
            for(map<int, int>::iterator i = neighbors.begin(); i != neighbors.end(); i++){
                int neighborV = i->first;
                int neighborT = i->second;
                findMin.push(vector<int>{neighborT + minTimes[nextV], neighborV});
            }
        }
        return -1;
    }
};

int main(){
    vector<vector<int>> G{{1,2,1}};

    Solution* S = new Solution();
    cout << S->networkDelayTime(G, 2, 2) << endl;
    return 0;
}