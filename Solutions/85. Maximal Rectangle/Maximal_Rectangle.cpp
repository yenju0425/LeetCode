#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution{
private:
    int M;
    int N;
    vector<int> heights;

public:
    int largestRectangleArea(vector<int> &heights){
        int maxArea = 0;

        vector<vector<int>> S; //stack
        
        int heights_size = heights.size();
        for(int i = 0; i < heights_size; i++){
            int temp = i;

            while(!S.empty() and S.back()[0] > heights[i]){
                temp    = S.back()[1];
                maxArea = max(maxArea, S.back()[0] * (i - S.back()[1]));
                S.pop_back();
            }

            S.push_back(vector<int>{heights[i], temp});
        }

        int size = S.size();
        for(int i = 0; i < size; i++){
            maxArea = max(maxArea, S[i][0] * (heights_size - S[i][1]));
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>> &matrix){
        this->M = matrix.size();
        this->N = matrix[0].size();
        this->heights = vector<int>(N, 0);

        int maxArea = 0;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                heights[j] = (heights[j] + 1) * (matrix[i][j] != '0'); //'0': reset heights[j]; else: heights[j] = heights[j] + 1
            }

            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};

int main(){
    Solution *S = new Solution();
    
    //input
    vector<vector<char>> matrix{
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    cout << S->maximalRectangle(matrix) << endl;

    return 0;
}