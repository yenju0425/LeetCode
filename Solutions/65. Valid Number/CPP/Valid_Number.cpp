#include <iostream>

using namespace std;

enum state {  // finite state machine
    init,
    S_,
    bD,
    D_,
    _D,
    aD,
    E,
    eS,
    N
};

class Solution {
public:
    bool isNumber(string s) {
        state S = init;
        for (string::iterator i = s.begin(); i != s.end(); i = i + 1) {
            switch (S) {
                case init:
                    if (*i == '+' || *i == '-') {
                        S = S_;
                    } else if (*i >= '0' && *i <= '9') {
                        S = bD;
                    } else if (*i == '.') {
                        S = D_;
                    } else {
                        return false;
                    }
                    break;

                case S_:
                    if (*i >= '0' && *i <= '9') {
                        S = bD;
                    } else if (*i == '.') {
                        S = D_;
                    } else {
                        return false;
                    }
                    break;

                case bD:
                    if (*i >= '0' && *i <= '9') {
                        S = bD;
                    } else if (*i == '.') {
                        S = _D;
                    } else if (*i == 'E' || *i == 'e') {
                        S = E;
                    } else {
                        return false;
                    }
                    break;

                case D_:
                    if (*i >= '0' && *i <= '9') {
                        S = aD;
                    } else {
                        return false;
                    }
                    break;

                case _D:
                    if (*i >= '0' && *i <= '9') {
                        S = aD;
                    } else if (*i == 'E' || *i == 'e') {
                        S = E;
                    } else {
                        return false;
                    }
                    break;

                case aD:
                    if (*i >= '0' && *i <= '9') {
                        S = aD;
                    } else if (*i == 'E' || *i == 'e') {
                        S = E;
                    } else {
                        return false;
                    }
                    break;

                case E:
                    if (*i == '+' || *i == '-') {
                        S = eS;
                    } else if (*i >= '0' && *i <= '9') {
                        S = N;
                    } else {
                        return false;
                    }
                    break;

                case eS:
                    if (*i >= '0' && *i <= '9') {
                        S = N;
                    } else {
                        return false;
                    }
                    break;

                case N:
                    if (*i >= '0' && *i <= '9') {
                        S = N;
                    } else {
                        return false;
                    }
                    break;

                default:
                    return false;
            }
        }
        if (S != bD && S != _D && S != aD && S != N) {
            return false;
        }
        return true;
    }
};

int main() {
    Solution S;

    // input
    string s = "-3.4e3";

    cout << S.isNumber(s) << endl;

    return 0;
}
