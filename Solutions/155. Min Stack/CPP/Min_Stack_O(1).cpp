#include <iostream>
#include <vector>

using namespace std;

class MinStack{
private:
    vector<int> minVal;
    vector<int> S;

public:
    void push(int val){
        if(minVal.empty() or val < minVal.back()){
            minVal.push_back(val);
        }
        else{
            minVal.push_back(minVal.back());
        }
        S.push_back(val);
    }
    
    void pop(){
        minVal.pop_back();
        S.pop_back();
    }
    
    int top(){
        return S.back();
    }
    
    int getMin(){
        return minVal.back();
    }
};

int main(){
    MinStack *MS = new MinStack();

    MS->push(-2);
    MS->push(0);
    MS->push(-3);

    cout << MS->getMin() << endl;

    MS->pop();
    
    cout << MS->top() << endl;
    cout << MS->getMin() << endl;

    return 0;
}