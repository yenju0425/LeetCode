#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Server{
    int time;
    vector<int> neighbors;

    Server(){
        time = -1;
        neighbors = vector<int>{};
    }
};

class Servers{
private:
    int numOfconnections;
    vector<vector<int>> connections;
    vector<vector<int>> CCs;
    vector<Server*> servers;

public:
    Servers(int n, vector<vector<int>> c){
        connections = c;
        numOfconnections = c.size();

        for(int i = 0; i < n; i++){
            servers.push_back(new Server());
        }

        for(int i = 0; i < numOfconnections; i++){
            int id0 = connections[i][0];
            int id1 = connections[i][1];
            servers[id0]->neighbors.push_back(id1);
            servers[id1]->neighbors.push_back(id0);
        }
    }

    void setCGs(int id, int parent, int time){
        servers[id]->time = time;

        int numOfneighbors = servers[id]->neighbors.size();
        int minTime = time;
        for(int i = 0; i < numOfneighbors; i++){
            int neighbor = servers[id]->neighbors[i];
            if(neighbor == parent){
                continue;
            }

            if(servers[neighbor]->time == -1){
                setCGs(neighbor, id, time + 1);
            }
            minTime = min(minTime, servers[neighbor]->time);
        }

        if(time == minTime and parent != -1){ //magic
            CCs.push_back(vector<int>{parent, id});
        }

        servers[id]->time = minTime;
    }

    vector<vector<int>> findCriticalConnections(){
        //DFS
        setCGs(0, -1, 0);
        return CCs;
    }
};

class Solution{
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections){
        //build servers
        Servers* S = new Servers(n, connections);

        //find CCs
        vector<vector<int>> CCs = S->findCriticalConnections();
        return CCs;
    }
};

int main(){
    Solution* S = new Solution();
    vector<vector<int>> C{{0,1},{0,2},{0,3},{2,4},{3,5},{5,4},{5,6}};
    vector<vector<int>> result = S->criticalConnections(7, C);
    for(auto i : result){
        cout << '(' << i[0] << ", " << i[1] << ')' << endl;
    }
    return 0;
}