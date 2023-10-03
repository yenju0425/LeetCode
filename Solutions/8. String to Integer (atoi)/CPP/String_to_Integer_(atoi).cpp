#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        /*
            state = 0: terminate
            state = 1: wait
            state = 2: read
        */
        int state = 1;
        int stringLength = s.length();
        int reader = 0;
        int signBit = 1; //set default to '+'
        long outputNumber = 0;

        while(state && reader < stringLength) {
            char character = s[reader];
            switch(state) {
                case 1:
                    if(character == ' ') {
                        //state = 1; state remain the same
                    }
                    else if(character == '+' || character == '-') {
                        state = 2;
                        if(character == '-') {
                            signBit = -1;
                        }
                    }
                    else if(character >= '0' && character <= '9') {
                        state = 2;
                        outputNumber = int(character) - '0'; //transfer the ascii code to integer, and store it into the outputNumber
                    }
                    else { //get invalid character
                        state = 0;
                    }
                    break;

                case 2:
                    if(character >= '0' && character <= '9') {
                        //state = 3; state remain the same

                        //overflow detection
                        outputNumber = outputNumber  *10 + signBit  *(int(character) - '0');
                        if(outputNumber > 2147483647) {
                            outputNumber = 2147483647;
                            state = 0;
                        }
                        else if(outputNumber < -2147483648) {
                            outputNumber = -2147483648;
                            state = 0;
                        }
                    }
                    else { //get invalid character
                        state = 0;
                    }
                    break;

                default:
                    cout << "error" << endl;
                    break;
            }
            reader = reader + 1; //move the reader to the next character
        }

        return int(outputNumber);
    }
};

int main() {
    Solution S;

    //input
    string s = "-21474836";

    cout << S.myAtoi(s) << endl;

    return 0;
}
