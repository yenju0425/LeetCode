#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class SmallestInfiniteSet {
private:
    int front;
    unordered_set<int> US;  // contains all the removed integers

public:
    SmallestInfiniteSet() { front = 1; }

    int popSmallest() {
        int smallest = front;

        US.insert(front);
        while (US.count(front)) {  // get the fisrt "not removed" integer
            front = front + 1;
        }

        return smallest;
    }

    void addBack(int num) {
        US.erase(num);
        front = min(front, num);
    }
};

int main() {
    SmallestInfiniteSet* SIS = new SmallestInfiniteSet();

    cout << SIS->popSmallest() << endl;
    cout << SIS->popSmallest() << endl;
    cout << SIS->popSmallest() << endl;

    SIS->addBack(1);

    cout << SIS->popSmallest() << endl;
    cout << SIS->popSmallest() << endl;
    cout << SIS->popSmallest() << endl;

    return 0;
}
