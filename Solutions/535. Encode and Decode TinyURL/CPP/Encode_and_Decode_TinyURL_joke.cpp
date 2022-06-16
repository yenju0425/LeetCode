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

    string url = "https://www.apple.com/tw/";

    string encode = S->encode(url);
    string decode = S->decode(encode);

    cout << encode << endl;
    cout << decode << endl;

    return 0;
}