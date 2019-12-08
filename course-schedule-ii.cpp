//https://leetcode.com/problems/course-schedule-ii/
class Solution {
    vector<int> result;
    bool hasCycle;
    vector<int> white; 
    vector<vector<int>> graph;
    unordered_set<int> gray; 
    int n;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        if (numCourses == 0)
            return (vector<int>());
        n = numCourses;
        hasCycle = false;
        white = vector<int>(n, 0);
        result = vector<int>(n);
        graph = vector<vector<int>>(n);
        for (auto x : prerequisites)
            graph[x[1]].push_back(x[0]);
        for (int i = 0; i < numCourses; i++)
            if (!white[i])
                dfs(i);
        if (hasCycle)
            return (vector<int>());
        return (result);
    }

    void dfs(int node) {
        if (hasCycle || white[node])
            return;
        white[node] = 1;
        gray.insert(node);   
        for (int ele : graph[node]) {
            if (gray.find(ele) != gray.end()) {
                hasCycle = true;
                return;
            }
            dfs(ele);
        }
        gray.erase(gray.find(node));
        result[--n] = node;
    }
};
