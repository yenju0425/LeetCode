#include <iostream>
#include <vector>

using namespace std;

class Solution{
private:
    vector<string> result;

public:
    void parenthesisGenerater(int left, int right, int counter, string p){
        if(left == 0 and right == 0){
            result.push_back(p);
            return;
        }

        if(counter > 0 and right > 0){
            //add right
            parenthesisGenerater(left, right - 1, counter - 1, p + string(")"));
        }

        if(left > 0){
            //add left
            parenthesisGenerater(left - 1, right, counter + 1, p + string("("));;
        }
    }

    vector<string> generateParenthesis(int n){
        parenthesisGenerater(n, n, 0, "");
        return result;
    }
};

int main(){
    Solution* S = new Solution();

    vector<string> P = S->generateParenthesis(3);

    for(auto i : P){
        cout << i << endl;
    }

    return 0;
}