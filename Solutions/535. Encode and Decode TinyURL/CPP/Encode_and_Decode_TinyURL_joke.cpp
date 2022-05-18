#include <iostream>

using namespace std;

class Solution{
public:

    string encode(string longUrl){
        return longUrl;
    }

    string decode(string shortUrl){
        return shortUrl;
    }
};

int main(){
    Solution *S = new Solution();

    string s = "https://www.apple.com/tw/";
    string e = S->encode(s);
    string d = S->decode(e);

    cout << e << endl;
    cout << d << endl;

    return 0;
}