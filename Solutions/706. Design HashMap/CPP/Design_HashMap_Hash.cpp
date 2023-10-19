#include <iostream>
#include <map>
#include <vector>

using namespace std;

class MyHashMap {
private:
    vector<map<int, int>> HM;

public:
    MyHashMap() {
        HM = vector<map<int, int>>(1024);
    }

    void put(int key, int value) {
        int index = key & 1023;
        HM[index][key] = value;
    }

    int get(int key) {
        int index = key & 1023;
        if (HM[index].find(key) == HM[index].end()) {
            return -1;
        }
        return HM[index][key];
    }

    void remove(int key) {
        int index = key & 1023;
        HM[index].erase(key);
    }
};

int main() {
    MyHashMap* HM = new MyHashMap();

    HM->put(0, 1);
    HM->put(0, 3);
    HM->put(34, 2);
    HM->remove(0);

    cout << HM->get(0) << endl;

    return 0;
}
