#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int candy(vector<int> &ratings){
        int ratings_size = ratings.size();
        vector<int> numOfCandy(ratings_size, 1);

        //left to right
        for(int i = 1; i < ratings_size; i++){
            if(ratings[i] > ratings[i - 1]){
                numOfCandy[i] = max(numOfCandy[i], numOfCandy[i - 1] + 1);
            }
        }

        //right to left
        for(int i = ratings_size - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]){
                numOfCandy[i] = max(numOfCandy[i], numOfCandy[i + 1] + 1);
            }
        }

        int sum = 0;
        for(int i = 0; i < ratings_size; i++){
            sum = sum + numOfCandy[i];
        }

        return sum;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    vector<int> ratings{1, 2, 2};

    cout << S->candy(ratings) << endl;

    return 0;
}