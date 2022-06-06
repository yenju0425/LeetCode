#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution{
public:
    int minimumCardPickup(vector<int> &cards){
        int numOfCards  = cards.size();
        int minDistance = -1;

        map<int, int> db;
        for(int i = 0; i < numOfCards; i++){
            map<int, int>::iterator existingCard = db.find(cards[i]);
            if(existingCard != db.end()){
                int distance = i - existingCard->second + 1;
                if(minDistance == -1 or distance < minDistance){
                    minDistance = distance;
                }
            }
            db[cards[i]] = i;
        }

        return minDistance;
    }
};

int main(){
    vector<int> cards{3, 4, 5, 7, 99, 98, 3, 6, 1, 2, 1, 3};

    Solution* S = new Solution();

    cout << S->minimumCardPickup(cards) << endl;

    return 0;
}