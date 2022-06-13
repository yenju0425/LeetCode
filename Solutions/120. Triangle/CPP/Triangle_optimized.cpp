#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int minimumTotal(vector<vector<int>> &triangle){
        //calculate path sum from 0 ~ (maxDepth - 1)
        int maxDepth = triangle.size() - 1;

        if(maxDepth == 0){
            return triangle[0][0];
        }

        for(i = 1; i < maxDepth; i++){
            triangle[i][0] = triangle[i][0] + triangle[i - 1][0];
            for(int j = 1; j < i; j++){
                triangle[i][j] = triangle[i][j] + min(triangle[i - 1][j], triangle[i - 1][j - 1]);
            }
            triangle[i][i] = triangle[i][i] + triangle[i - 1][i - 1];
        }

        //look for the minimum path sum
        int result = triangle[maxDepth][0] + triangle[maxDepth - 1][0];
        for(int i = 1; i < maxDepth; i++){
            result = min(result, triangle[maxDepth][i] + min(triangle[maxDepth - 1][i], triangle[maxDepth - 1][i - 1]));
        }
        result = min(result, triangle[maxDepth][maxDepth] + triangle[maxDepth - 1][maxDepth - 1]);

        return result;
    }
};

int main(){
    Solution* S = new Solution();

    //input
    vector<vector<int>> triangle{
       {2},
       {3, 4},
       {6, 5, 7},
       {4, 1, 8, 3}
    };

    cout << S->minimumTotal(triangle) << endl;

    return 0;
}