#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void swap(int &a, int &b, int &c, int&d){
        int temp = a;
        a = d;
        d = c;
        c = b;
        b = temp;
    }

    void rotate(vector<vector<int>> &matrix){
        int m = matrix.size();

        int numOfLevel = m / 2;
        for(int i = 0; i < numOfLevel; i++){
            int maxColumnIdx = m - 1 - i;
            for(int j = i; j < maxColumnIdx; j++){
                int temp_i = m - 1 - i;
                int temp_j = m - 1 - j;
                swap(matrix[i][j], matrix[j][temp_i], matrix[temp_i][temp_j], matrix[temp_j][i]);
            }
        }
    }
};

int main(){
    Solution *S = new Solution();

    //input
    vector<vector<int>> matrix{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    S->rotate(matrix);

    for(auto i : matrix){
        for(auto j : i){
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}