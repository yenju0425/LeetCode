#include <iostream>
#include <vector>

using namespace std;

class MyHashSet {
    vector<vector<int>> HS;

public:
    MyHashSet() { HS = vector<vector<int>>(1024); }

    void add(int key) {
        int index = key & 1023;
        for (vector<int>::iterator i = HS[index].begin(); i != HS[index].end(); i = i + 1) {
            if (*i == key) {
                return;
            }
        }
        HS[index].push_back(key);
    }

    void remove(int key) {
        int index = key & 1023;
        for (vector<int>::iterator i = HS[index].begin(); i != HS[index].end(); i = i + 1) {
            if (*i == key) {
                HS[index].erase(i);
                return;
            }
        }
    }

    bool contains(int key) {
        int index = key & 1023;
        for (vector<int>::iterator i = HS[index].begin(); i != HS[index].end(); i = i + 1) {
            if (*i == key) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    MyHashSet* HS = new MyHashSet();

    HS->add(0);
    HS->add(0);
    HS->add(34);
    HS->remove(0);

    cout << HS->contains(34) << endl;

    return 0;
}
