#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int countLatticePoints(vector<vector<int>> &circles){
        int LP = 0;
        
        if(circles.empty()){
            return LP;
        }

        int x_min = circles[0][0] - circles[0][2];
        int x_max = circles[0][0] + circles[0][2];
        int y_min = circles[0][1] - circles[0][2];
        int y_max = circles[0][1] + circles[0][2];
        for(vector<vector<int>>::iterator i = circles.begin() + 1; i != circles.end(); i++){
            x_min = min(x_min, (*i)[0]-(*i)[2]);
            x_max = max(x_max, (*i)[0]+(*i)[2]);
            y_min = min(y_min, (*i)[1]-(*i)[2]);
            y_max = max(y_max, (*i)[1]+(*i)[2]);
        }

        for(int i = x_min; i <= x_max; i++){
            for(int j = y_min; j <= y_max; j++){
                for(vector<vector<int>>::iterator c = circles.begin(); c != circles.end(); c++){
                    if(((*c)[0] - i)*((*c)[0] - i) + ((*c)[1] - j)*((*c)[1] - j) <= (*c)[2] * (*c)[2]){
                        LP = LP + 1;
                        break;
                    }
                }
            }
        }

        return LP;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    vector<vector<int>> ciecles{
        {2, 2, 2}
    };

    cout << S->countLatticePoints(ciecles) << endl;

    return 0;
}