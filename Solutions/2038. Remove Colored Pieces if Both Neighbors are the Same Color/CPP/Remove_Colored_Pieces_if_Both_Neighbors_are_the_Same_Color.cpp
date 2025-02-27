#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        colors += '\0';  // Append null character as a sentinel

        int validMovesPlayerA = 0;
        int validMovesPlayerB = 0;

        char currentPlayer   = '\0';  // Initialize with the first character
        int consecutiveMoves = 0;

        for (const char& c : colors) {
            if (c == currentPlayer) {
                consecutiveMoves++;
            } else {
                if (currentPlayer == 'A') {
                    validMovesPlayerA += max(consecutiveMoves - 2, 0);
                } else if (currentPlayer == 'B') {
                    validMovesPlayerB += max(consecutiveMoves - 2, 0);
                }

                currentPlayer    = c;
                consecutiveMoves = 1;
            }
        }

        return validMovesPlayerA > validMovesPlayerB;
    }
};

int main() {
    Solution S;

    string colors = "ABBBBBBBAAA";

    cout << S.winnerOfGame(colors) << endl;

    return 0;
}
