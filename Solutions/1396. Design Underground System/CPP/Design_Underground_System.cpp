#include <iostream>
#include <tuple>
#include <vector>
#include <map>

using namespace std;

class UndergroundSystem{
private:
    map<int, tuple<string, int>> passengers;
    map<tuple<string, string>, vector<int>> DB;

public:
    void checkIn(int id, string stationName, int t){
        passengers[id] = tuple<string, int>{stationName, t};
    }
    
    void checkOut(int id, string stationName, int t){
        string startStation = get<0>(passengers[id]);
        int duration = t - get<1>(passengers[id]);

        tuple<string, string> start_end{startStation, stationName};

        auto iter = DB.find(start_end);
        if(iter != DB.end()){
            (iter->second)[0] += duration;
            (iter->second)[1] += 1;
        }
        else{
            DB[start_end] = vector<int>{duration, 1};
        }
        passengers.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation){
        double duration   = DB[tuple<string, string>{startStation, endStation}][0];
        int    passengers = DB[tuple<string, string>{startStation, endStation}][1];
        return duration/passengers;
    }
};
int main(){
    UndergroundSystem* U = new UndergroundSystem();

    U->checkIn(45, "Leyton", 3);
    U->checkIn(32, "Paradise", 8);
    U->checkIn(27, "Leyton", 10);
    U->checkOut(45, "Waterloo", 15);
    U->checkOut(27, "Waterloo", 20);
    U->checkOut(32, "Cambridge", 22);
    U->getAverageTime("Paradise", "Cambridge");
    U->getAverageTime("Leyton", "Waterloo");
    U->checkIn(10, "Leyton", 24);
    U->getAverageTime("Leyton", "Waterloo");
    U->checkOut(10, "Waterloo", 38);
    U->getAverageTime("Leyton", "Waterloo");

    return 0;
}