#include <iostream>
#include <random>
#include <ctime>
#include <unordered_map>

using namespace std;

class Solution {
private:
    string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    string prefix     = "https://www.shortURL.com/";
    int urlLength = 10;
    unordered_map<string, string> DB;

public:
    Solution(){
        srand(time(nullptr));
    }

    string encode(string longUrl) {
        string shortUrl = prefix;
        for(int i = 0; i < urlLength; i++){
            shortUrl += characters[rand() % 62];
        }
        DB[shortUrl] = longUrl;
        return shortUrl;
    }

    string decode(string shortUrl) {
        return DB[shortUrl];
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