#include <iostream>
#include <vector>

using namespace std;

class NestedInteger{
private:
    int* integer = nullptr;
    vector<NestedInteger> nestedList;

public:
    NestedInteger(int i){
        *integer = i;
    }
    NestedInteger(vector<NestedInteger> NI){
        nestedList = NI;
    }

    //Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const{
        return integer != nullptr;
    }

    //Return the single integer that this NestedInteger holds, if it holds a single integer
    //The result is undefined if this NestedInteger holds a nested list
    int getInteger() const{
        return *integer;
    }

    //Return the nested list that this NestedInteger holds, if it holds a nested list
    //The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const{
        return nestedList;
    }
};

class NestedIterator{
private:
    vector<NestedInteger>  N_Ints;
    vector<NestedIterator> N_Iters;
    int listSize;
    int index;

public:
    NestedIterator(vector<NestedInteger> &nestedList){
        N_Ints   = nestedList;
        listSize = nestedList.size();
        index    = 0;
        for(int i = 0; i < listSize; i++){
            vector<NestedInteger> temp;
            if(nestedList[i].isInteger() == false){
                temp = nestedList[i].getList();
            }
            N_Iters.push_back(temp);
        }
    }

    int next(){
        if(N_Ints[index].isInteger()){
            int temp = N_Ints[index].getInteger();
            index = index + 1;
            return temp;
        }
        else{
            int temp = N_Iters[index].next();
            if(N_Iters[index].hasNext() == false){
                index = index + 1;
            }
            return temp;
        }
    }

    bool hasNext(){
        while(index < listSize){
            if(N_Ints[index].isInteger() or N_Iters[index].hasNext()){
                return true;
            }
            index = index + 1;
        }
        return false;
    }
};

int main(){
    NestedInteger I0(vector<NestedInteger>{});

    vector<NestedInteger> V1{I0};

    NestedIterator* N = new NestedIterator(V1);
    while(N->hasNext()){
        cout << N->next() << ' ';
    }
    cout << endl;
    return 0;
}