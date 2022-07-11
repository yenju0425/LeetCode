#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    bool canChange(string start, string target){
        int n = start.length();

        vector<int> s_R_ids, s_L_ids, t_R_ids, t_L_ids;
        for(int i = 0; i < n; i++){
            if(start[i] == 'R'){
                s_R_ids.push_back(i);
            }
            else if(start[i] == 'L'){
                s_L_ids.push_back(i);
            }

            if(target[i] == 'R'){
                t_R_ids.push_back(i);
            }
            else if(target[i] == 'L'){
                t_L_ids.push_back(i);
            }
        }

        //check R
        int numOfR = s_R_ids.size();
        if(numOfR != t_R_ids.size()){
            return false;
        }
        for(int i = 0; i < numOfR; i++){
            if(t_R_ids[i] < s_R_ids[i]){
                return false;
            }
        }

        //check L
        int numOfL = s_L_ids.size();
        if(numOfL != t_L_ids.size()){
            return false;
        }
        for(int i = 0; i < numOfL; i++){
            if(t_L_ids[i] > s_L_ids[i]){
                return false;
            }
        }

        //check relative position
        start.erase(remove(start.begin(), start.end(), '_'), start.end());
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