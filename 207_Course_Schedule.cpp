//https://leetcode.com/problems/course-schedule/
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> result(numCourses);
    for (const auto& item : prerequisites) {
        result[item[0]].push_back(item[1]);
    }
    return result;
}
bool dfs(int i, vector<vector<int>>& g, vector<int>& v) {
    if (v[i] == -1){
        return false;
    }
    if (v[i] == 1){
        return true;
    }
    v[i] = -1;
    for (int i : g[i]) {
        if (!dfs(i, g, v)){
            return false;
        }
    }
    v[i] = 1;
    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> g = buildGraph(numCourses, prerequisites);
    vector<int> v(numCourses, 0);
    for (int i = 0; i < numCourses; i++) {
        if (!dfs(i, g, v)){
            return false;
        }
    }
    return true;
}

int main() {
    {
        int numCourses = 2;
        vector<vector<int>> prerequisites = {{1, 0}};
        cout << canFinish(numCourses, prerequisites);
    }
    {
        int numCourses = 2;
        vector<vector<int>> prerequisites = {{1, 0},
                                             {0, 1}};
        cout << canFinish(numCourses, prerequisites);
    }
    return 0;
}
