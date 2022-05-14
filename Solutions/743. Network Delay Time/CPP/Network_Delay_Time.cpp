#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;

class Vertex{
private:
    bool visited = false;
    map<int, int> adjList = {};

public:
    bool isVisied(){
        return visited;
    }

    void addEdge(int v, int w){
        adjList[v] = w;
    }
};

class Solution{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k){
        map<int, Vertex*> vertices;

        //build graph
        for(vector<vector<int>>::iterator i = times.begin(); i != times.end(); i++){
            int node1 = (*i)[0];
            int node2 = (*i)[1];
            int time  = (*i)[2];

            if(vertices[node1] == nullptr){
                vertices[node1] = new Vertex();
            }
            if(vertices[node2] == nullptr){
                vertices[node2] = new Vertex();
            }
            vertices[node1]->addEdge(node2, time);
            vertices[node2]->addEdge(node1, time);
        }

        //Dijkstra Algorithm

    }
};

int main(){
    vector<vector<int>> G{{2,1,1},{2,3,1},{3,4,1}};

    Solution* S = new Solution();
    S->networkDelayTime(G, 2, 4);
    return 0;
}