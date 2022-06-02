#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	vector<vector<int>> transpose(vector<vector<int>> &matrix){
		int M = matrix.size();
		int N = matrix[0].size();

		//swap rows and columns
		vector<vector<int>> result(N, vector<int>(M, 0));
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				result[i][j] = matrix[j][i];
			}
		}

		return result;
	}
};

int main(){
    Solution* S = new Solution();

    vector<vector<int>> matrix{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<int>> result = S->transpose(matrix);

    for(auto i : result){
        for(auto j : i){
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}