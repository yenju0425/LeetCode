#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    string simplifyPath(string path){
        vector<string> directories;

        int idx = 0;
        int path_length = path.length();
        while(idx < path_length){
            if(path[idx] == '/'){
                idx = idx + 1;
                continue;
            }

            //read next dir
            string dir;
            while(idx < path_length and path[idx] != '/'){
                dir.push_back(path[idx]);
                idx = idx + 1;
            }

            if(dir == ".."){
                if(!directories.empty()){
                    directories.pop_back();
                }
            }
            else if(dir == "."){
                continue;
            }
            else{
                directories.push_back(dir);
            }
        }

        if(directories.empty()){
            directories.push_back("");
        }

        string result;
        int numOfDirectories = directories.size();
        for(int i = 0; i < numOfDirectories; i++){
            result.push_back('/');
            result.append(directories[i]);
        }

        return result;
    }
};

int main(){
    Solution *S = new Solution();

    //input
    string path = "/../";

    cout << S->simplifyPath(path) << endl;

    return 0;
}