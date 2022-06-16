#include <iostream>
#include <queue>

using namespace std;

//push to back, peek/pop from front, size and is empty
class MyStack{
private:
    queue<int> Q;

public:
    MyStack(){
    }
    
    void push(int x){
        int Q_Size = Q.size();
        Q.push(x);
        for(int i = 0; i < Q_Size; i++){
            Q.push(Q.front());
            Q.pop();
        }
    }
    
    int pop(){
        int S_top = Q.front();
        Q.pop();
        return S_top;
    }
    
    int top(){
        return Q.front();
    }
    
    bool empty(){
        return Q.empty();
    }
};

int main(){
    MyStack *S = new MyStack();

    S->push(1);
    S->push(2);

    cout << S->top() << endl;
    cout << S->pop() << endl;
    cout << S->top() << endl;

    return 0;
}