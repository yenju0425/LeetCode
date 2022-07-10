#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity){
        sort(buses.begin(),      buses.end());
        sort(passengers.begin(), passengers.end());

        vector<int>::iterator nxt_passenger = passengers.begin();
        for(vector<int>::iterator bus = buses.begin(); bus != buses.end() - 1; bus++){
            nxt_passenger = min(nxt_passenger + capacity, upper_bound(nxt_passenger, passengers.end(), *bus));
        }

        //last bus
        vector<int>::iterator temp = min(nxt_passenger + capacity, upper_bound(nxt_passenger, passengers.end(), buses.back()));
        if(temp - nxt_passenger == capacity){ //last bus is full
            nxt_passenger = temp - 1;
        }
        else{
            nxt_passenger = passengers.insert(temp, buses.back() + 1);
        }

        for(vector<int>::iterator iter = nxt_passenger; iter != passengers.begin(); iter--){
            if(*iter - 1 != *(iter - 1)){
                return *iter - 1;
            }
        }

        return passengers.front() - 1;
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    int capacity = 1;
    vector<int> buses{3};
    vector<int> passengers{4};

    cout << S->latestTimeCatchTheBus(buses, passengers, capacity) << endl;

    return 0;
}