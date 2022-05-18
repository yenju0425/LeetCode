#include <iostream>
#include <vector>
#include <map>

using namespace std;

class MyHashMap{
private:
    vector<map<int, int>> H;

public:
    MyHashMap(){
        H = vector<map<int, int>>(1024);
    }
    
    void put(int key, int value){
        int index = key & 1023;
        H[index][key] = value;
    }
    
    int get(int key){
        int index = key & 1023;
        if(H[index].find(key) == H[index].end()){
            return -1;
        }
        return H[index][key];
    }
    
    void remove(int key){
        int index = key & 1023;
        H[index].erase(key);
    }
};

int main(){
    MyHashMap* H = new MyHashMap();
    H->put(0, 1);
    H->put(0, 3);
    H->put(34, 2);
    H->remove(0);
    cout << H->get(0) << endl;
    return 0;
}