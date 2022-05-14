#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Vertex{
private:
    int time;
    bool visited;
    map<int, int> adjList;

public:
    Vertex(){
        time = numeric_limits<int>::max();
        visited = false;
    }

    //Element access:
    int timeToSource(){
        return time;
    }
    map<int, int> getAdjList(){
        return adjList;
    }
    bool isVisited(){
        return visited;
    }

    //Modifiers:
    void setTime(int t){
        time = t;
    }
    void addEdge(int v, int t){
        adjList[v] = t;
    }
    void visit(){
        visited = true;
    }
};

class Solution{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k){ //n vertices, start from k
        map<int, Vertex*> vertices;
        for(int i = 1; i <= n; i++){
            vertices[i] = nullptr;
        }
        int numVisited = 0;

        //build graph
        for(vector<vector<int>>::iterator i = times.begin(); i != times.end(); i++){
            int v1 = (*i)[0];
            int v2 = (*i)[1];
            int t  = (*i)[2];

            if(vertices[v1] == nullptr){
                vertices[v1] = new Vertex();
            }
            if(vertices[v2] == nullptr){
                vertices[v2] = new Vertex();
            }

            vertices[v1]->addEdge(v2, t);
        }

        //Dijkstra's Algorithm
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> findMin; //findMin[0]: time needed; findMin[1]: next vertex;
        findMin.push(vector<int>{0, k});
        while(!findMin.empty()){
            int T = findMin.top()[0];
            int V = findMin.top()[1];
            findMin.pop();

            if(vertices[V]->isVisited()){
                continue;
            }

            vertices[V]->visit();
            vertices[V]->setTime(T);
            numVisited = numVisited + 1;

            if(numVisited == n){ //target found
                return vertices[V]->timeToSource();
            }

            //update neighbors
            map<int, int> neighbors = vertices[V]->getAdjList();
            for(map<int, int>::iterator i = neighbors.begin(); i != neighbors.end(); i++){
                int neighborV = i->first;
                int neighborT = i->second;
                if(vertices[neighborV]->isVisited() == false){
                    findMin.push(vector<int>{T + neighborT, neighborV});
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<vector<int>> G{{1,2,1},{2,3,7},{1,3,4},{2,1,2}};

    Solution* S = new Solution();
    cout << S->networkDelayTime(G, 4, 1) << endl;
    return 0;
}