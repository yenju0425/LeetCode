#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int numOfWords = words.size();
        vector<int> word_length(numOfWords, 0);
        for (int i = 0; i < numOfWords; ++i) {
            word_length[i] = words[i].length();
        }

        vector<string> result;

        int idx = 0;
        while (idx != numOfWords) {
            // select words for next line
            vector<string> buffer;
            int wordsCounter = 0;
            int width        = 0;
            int nextWidth    = (idx < numOfWords) ? word_length[idx] : INT_MAX;
            while (nextWidth <= maxWidth) {
                buffer.push_back(words[idx]);
                idx          = idx + 1;
                wordsCounter = wordsCounter + 1;
                width        = nextWidth;
                nextWidth    = (idx < numOfWords) ? nextWidth + word_length[idx] + 1 : INT_MAX;
            }

            // write into nextLine
            string nextLine;
            int totalSpace = maxWidth - width + wordsCounter - 1;
            for (int i = 0; i < wordsCounter; ++i) {
                nextLine.append(buffer[i]);

                int space;
                if (i == wordsCounter - 1) {  // last word
                    space = totalSpace;
                } else if (nextWidth == INT_MAX) {  // last line, every space is 1
                    space = 1;
                } else {
                    space = ceil(float(totalSpace) / (wordsCounter - 1 - i));
                }

                nextLine.append(space, ' ');
                totalSpace = totalSpace - space;
            }

            result.push_back(nextLine);
        }

        return result;
    }
};

int main() {
    Solution S;

    int maxWidth = 16;
    vector<string> words{"What", "must", "be", "acknowledgment", "shall", "be"};

    vector<string> result = S.fullJustify(words, maxWidth);

    for (auto i : result) {
        cout << i << endl;
    }

    return 0;
}
