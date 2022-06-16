#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Vertex{
private:
    bool visited;
    int time;
    vector<int> adjList;

public:
    Vertex(int n){
        visited = false;
        time = -1;                    //-1: invalid
        adjList = vector<int>(n, -1); //-1: invalid
    }

    //Element access:
    int timeToSource(){
        return time;
    }
    vector<int> getAdjList(){
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
    int networkDelayTime(vector<vector<int>> &times, int n, int k){ //n vertices, start from k
        vector<Vertex*> vertices(n + 1, nullptr); //vertices[0] is a dummy Vertex
        int numVisited = 0;

        //build graph
        for(vector<vector<int>>::iterator i = times.begin(); i != times.end(); i++){
            int v1 = (*i)[0];
            int v2 = (*i)[1];
            int t  = (*i)[2];

            if(vertices[v1] == nullptr){
                vertices[v1] = new Vertex(n + 1);
            }
            if(vertices[v2] == nullptr){
                vertices[v2] = new Vertex(n + 1);
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
            vector<int> neighbors = vertices[V]->getAdjList();
            for(int i = 1; i <= n; i++){
                int neighborV = i;
                int neighborT = neighbors[i];
                if(neighborT == -1 or vertices[neighborV]->isVisited()){
                    continue;
                }
                findMin.push(vector<int>{T + neighborT, neighborV});
            }
        }
        return -1;
    }
};

int main(){
    Solution *S = new Solution();
    
    //inputs
    int n = 4;
    int k = 2;
    vector<vector<int>> times{{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};

    cout << S->networkDelayTime(times, n, k) << endl;

    return 0;
}