#include <iostream>
#include <vector>

using namespace std;

struct Data {
    int val        = 0;
    Data* nextData = nullptr;
};

class Iterator {
private:
    Data* data;  // pointer to the current data in the lisked-list

public:
    Iterator(const vector<int>& nums) {
        Data* preNode = nullptr;
        for (vector<int>::const_iterator i = nums.end() - 1; i - nums.begin() >= 0; i--) {
            Data* node     = new Data();
            node->val      = *i;
            node->nextData = preNode;
            preNode        = node;
        }
        data = preNode;
    }

    Iterator(const Iterator& iter) {  // Think: why do we need to create an Iterator using another Iterator? => Cause we
                                      // need to PEEK!
        data = iter.data;
    }

    // Returns the nextData element in the iteration.
    int next() {
        if (data != nullptr) {
            data = data->nextData;
            return data->val;
        } else {
            return -1;
        }
    }

    // Returns true if the iteration has more elements.
    bool hasNext() const { return (data != nullptr and data->nextData != nullptr); }
};

class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {  // calling parent's constructor
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        PeekingIterator temp = (*this);  // duplicate (don't want to move the current index to next)
        return temp.next();
    }

    int next() { return Iterator::next(); }

    bool hasNext() const { return Iterator::hasNext(); }
};

int main() {
    // input
    vector<int> v{};

    PeekingIterator* P = new PeekingIterator(v);

    cout << P->hasNext() << endl;
    cout << P->peek() << endl;
    cout << P->hasNext() << endl;
    cout << P->next() << endl;
    cout << P->peek() << endl;

    return 0;
}
