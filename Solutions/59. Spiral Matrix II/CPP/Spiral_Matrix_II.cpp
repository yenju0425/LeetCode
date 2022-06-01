#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> generateMatrix(int n){
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        for(int i = 0; i < n; i = i + 1){
            for(int j = 0; j < n; j = j + 1){
                int u = i;
                int r = n - j - 1;
                int d = n - i - 1;
                int l = j;
                int margin  = min(min(u, r), min(d, l));
                int number  = 1 + 4 * (n - margin) * margin; //outerspace = ((n - 1) + (n + 1 - 2 * margin)) * margin / 2 * 4;
                if(u == margin){
                    number = number +                        l - margin;
                }
                else if(r == margin){
                    number = number +   (n - 1 - 2*margin) + u - margin;
                }
                else if(d == margin){
                    number = number + 2*(n - 1 - 2*margin) + r - margin;
                }
                else{ //l == margin
                    number = number + 3*(n - 1 - 2*margin) + d - margin;
                }
                matrix[i][j] = number;
            }
        }
        return matrix;
    }
};

int main(){
    int n = 4;

    Solution* S = new Solution;

    vector<vector<int>> ans = S->generateMatrix(n);
    for(int i = 0; i < n; i = i + 1){
        for(int j = 0; j < n; j = j + 1){
             cout << ans[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}