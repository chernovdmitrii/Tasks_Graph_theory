//https://leetcode.com/problems/clone-graph/
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    unordered_map<Node *, Node *> copies;

    Node *cloneGraph(Node *node) {
        if (!node) {
            return NULL;
        }
        Node *result = new Node(node->val, {});
        copies[node] = result;
        queue < Node * > todo;
        todo.push(node);
        while (!todo.empty()) {
            Node *cur = todo.front();
            todo.pop();
            for (Node *neighbor : cur->neighbors) {
                if (copies.find(neighbor) == copies.end()) {
                    copies[neighbor] = new Node(neighbor->val, {});
                    todo.push(neighbor);
                }
                copies[cur]->neighbors.push_back(copies[neighbor]);
            }
        }
        return result;
    }
};
