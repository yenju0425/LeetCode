#include <iostream>

using namespace std;

class Solution{
public:
    int maxNumberOfBalloons(string text){
        int charCount[26] = {0};
    
        int text_size = text.length();
        for(int i = 0; i < text_size; i++){
            int index = text[i] - 'a';
            charCount[index] = charCount[index] + 1;
        }

        return min(min(min(charCount['b' - 'a'], charCount['a' - 'a']), min(charCount['l' - 'a'] / 2, charCount['o' - 'a'] / 2)), charCount['n' - 'a']);
    }
};

int main(){
    Solution *S = new Solution();

    //input
    string text = "loonbalxballpoon";

    cout << S->maxNumberOfBalloons(text) << endl;

    return 0;
}