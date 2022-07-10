#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class SmallestInfiniteSet{
private:
    int front;
    unordered_set<int> S; //contains all the removed integers

public:
    SmallestInfiniteSet(){
        front = 1;
    }
    
    int popSmallest(){
        int pop = front;
    
        S.insert(front);

        front = front + 1;
        while(S.count(front)){
            front = front + 1;
        }

        return pop;
    }
    
    void addBack(int num){
        S.erase(num);
        if(num < front){
            front = num;
        }
    }
};

int main(){
    SmallestInfiniteSet *SIS = new SmallestInfiniteSet();

    //inputs
    cout << SIS->popSmallest() << endl;
    cout << SIS->popSmallest() << endl;
    cout << SIS->popSmallest() << endl;

    SIS->addBack(1);
    
    cout << SIS->popSmallest() << endl;
    cout << SIS->popSmallest() << endl;
    cout << SIS->popSmallest() << endl;

    return 0;
}