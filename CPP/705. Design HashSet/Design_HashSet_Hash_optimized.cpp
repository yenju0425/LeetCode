#include <iostream>
#include <vector>

using namespace std;

class MyHashSet {
    vector<vector<int>> H;

public:
    MyHashSet() {
        H = vector<vector<int>>(1024);
    }
    
    void add(int key) {
        int index = key & 1023;
        for(vector<int>::iterator i = H[index].begin(); i != H[index].end(); i = i + 1){
            if(*i == key){
                return;
            }
        }
        H[index].push_back(key);
    }
    
    void remove(int key) {
        int index = key & 1023;
        for(vector<int>::iterator i = H[index].begin(); i != H[index].end(); i = i + 1){
            if(*i == key){
                H[index].erase(i);
                return;
            }
        }
    }
    
    bool contains(int key) {
        int index = key & 1023;
        for(vector<int>::iterator i = H[index].begin(); i != H[index].end(); i = i + 1){
            if(*i == key){
                return true;
            }
        }
        return  false;
    }
};

int main(){
    MyHashSet *H = new MyHashSet();
    H->add(0);
    H->add(0);
    H->add(34);
    H->remove(0);
    cout << H->contains(34) << endl;
    return 0;
}