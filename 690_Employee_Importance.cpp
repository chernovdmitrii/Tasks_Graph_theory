//https://leetcode.com/problems/employee-importance/

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee *> employees, int id) {

        unordered_map <int, Employee*> m;
        for (auto x: employees){
            m[x->id] = x; 
        } 
        int sum = 0;

        deque < Employee * > q;
        q.push_back(m[id]);

        while (!q.empty()) {
            auto p = q.front();
            q.pop_front();
            for (auto x: p->subordinates) q.push_back(m[x]);
            sum += p->importance;
        }
        return sum;
    }
};
