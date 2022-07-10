#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    bool canChange(string start, string target){
        int n = start.length();

        vector<int> start_R_idx;
        vector<int> start_L_idx;
        vector<int> target_R_idx;
        vector<int> target_L_idx;
        for(int i = 0; i < n; i++){
            if(start[i] == 'R'){
                start_R_idx.push_back(i);
            }
            else if(start[i] == 'L'){
                start_L_idx.push_back(i);
            }

            if(target[i] == 'R'){
                target_R_idx.push_back(i);
            }
            else if(target[i] == 'L'){
                target_L_idx.push_back(i);
            }
        }

        //check R's
        int numOfR = start_R_idx.size();
        if(numOfR != target_R_idx.size()){
            return false;
        }
        for(int i = 0; i < numOfR; i++){
            if(target_R_idx[i] < start_R_idx[i]){
                return false;
            }
        }

        //check L's
        int numOfL = start_L_idx.size();
        if(numOfL != target_L_idx.size()){
            return false;
        }
        for(int i = 0; i < numOfL; i++){
            if(target_L_idx[i] > start_L_idx[i]){
                return false;
            }
        }

        //check relative posistion
        start.erase( remove(start.begin(),  start.end(),  '_'), start.end());
        target.erase(remove(target.begin(), target.end(), '_'), target.end());
        if(start != target){
            return false;
        }

        return true;
    }
};

int main(){
    Solution *S = new Solution();

    //inputs
    string start  = "_R";
    string target = "L_";

    cout << S->canChange(start, target) << endl;

    return 0;
}