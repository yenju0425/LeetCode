//Reference: https://leetcode.com/problems/course-schedule-iii/solution
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution{
public:
    int scheduleCourse(vector<vector<int>> &courses){
        sort(courses.begin(), courses.end(), [](vector<int> &c1, vector<int> &c2){
            return c1.back() < c2.back();
        });
    
        vector<int> courseTaken; //store the indices of the taken courses
        int currentTime = 0;

        int numOfCourses = courses.size();
        for(int i = 0; i < numOfCourses; i++){
            int endTime = currentTime + courses[i][0];
            if(endTime <= courses[i][1]){
                currentTime = endTime;
                courseTaken.push_back(i);
            }
            else{ //look for a course to replace it
                int maxIdx = i;
                int numOfCourseTaken = courseTaken.size();
                for(int j = 0; j < numOfCourseTaken; j++){
                    if(courses[courseTaken[j]][0] > courses[maxIdx][0]){
                        swap(courseTaken[j], maxIdx);
                    }
                }
            
                if(maxIdx != i){
                    currentTime = currentTime - courses[maxIdx][0] + courses[i][0];
                }
            }
        }

        return courseTaken.size();
    }
};

int main(){
    Solution *S = new Solution();

    //input
    vector<vector<int>> courses{
        { 100,  200},
        { 200, 1300},
        {1000, 1250},
        {2000, 3200}
    };

    cout << S->scheduleCourse(courses) << endl;

    return 0;
}