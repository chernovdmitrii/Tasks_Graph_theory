// https://leetcode.com/problems/maximum-depth-of-n-ary-tree
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == NULL){
            return 0;
        }
        int max = 0; 
        for (auto i : root -> children){
            //cout << i -> val << endl; 
            int temp = maxDepth(i);
            if (max < temp){
                max = temp; 
            }
        }
        return 1 + max; 
    }
};
