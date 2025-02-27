#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class MinStack {
private:
    vector<int> ordered_S;
    vector<int> S;

public:
    void push(int val) {
        ordered_S.insert(lower_bound(ordered_S.begin(), ordered_S.end(), val), val);
        S.push_back(val);
    }

    void pop() {
        ordered_S.erase(lower_bound(ordered_S.begin(), ordered_S.end(), S.back()));
        S.pop_back();
    }

    int top() { return S.back(); }

    int getMin() { return ordered_S.front(); }
};

int main() {
    MinStack* MS = new MinStack();

    MS->push(-2);
    MS->push(0);
    MS->push(-3);

    cout << MS->getMin() << endl;

    MS->pop();

    cout << MS->top() << endl;
    cout << MS->getMin() << endl;

    return 0;
}
