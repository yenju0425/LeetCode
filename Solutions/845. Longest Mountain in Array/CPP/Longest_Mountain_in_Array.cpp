#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int longestMountain(vector<int> &arr){
        int state = 0; //0: invalid, 1: acc, -1: dec
        int maxSize     = 0;
        int currentSize = 0;

        if(arr.size() <= 1){
            return 0;
        }

        arr.push_back(*(arr.end() - 1)); //keep the dynamic of the last element

        for(vector<int>::iterator iter = arr.begin(); iter + 1 != arr.end(); iter = iter + 1){
            switch(state){
                case 0:
                    if(*iter < *(iter + 1)){
                        currentSize = 1;
                        state = 1;
                    }
                    break;

                case 1:
                    if(*iter < *(iter + 1)){
                        currentSize = currentSize + 1;
                    }
                    else if(*iter == *(iter + 1)){
                        state = 0;
                        currentSize = 0;
                    }
                    if(*iter > *(iter + 1)){
                        state = -1;
                        currentSize = currentSize + 1;
                    }
                    break;

                case -1:
                    if(*iter < *(iter + 1)){
                        state = 1;
                        currentSize = currentSize + 1;
                        maxSize = max(maxSize, currentSize);
                        currentSize = 1;
                    }
                    else if(*iter == *(iter + 1)){
                        state = 0;
                        currentSize = currentSize + 1;
                        maxSize = max(maxSize, currentSize);
                        currentSize = 0;
                    }
                    if(*iter > *(iter + 1)){
                        currentSize = currentSize + 1;
                    }
                    break;
                    
                default:
                    break;
            }
        }
    
        return maxSize;
    }
};

int main(){
    Solution* S = new Solution();

    //input
    vector<int> M{0, 1, 2, 3, 4, 5, 4, 3, 2, 1, 0};

    cout << S->longestMountain(M) << endl;

    return 0;
}